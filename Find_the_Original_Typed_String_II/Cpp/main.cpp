#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string_view>

#define LOG_DEBUG(x) (std::cout << x << std::endl)

#define Assert(condition)

struct TestSuit {
public:
    std::string word;
    int k;
};

template <typename T>
std::ostream &operator<<(std::ostream &output, const long long &input) {
    std::cout << input << std::endl;
    return output;
}

template <typename T>
std::ostream &operator<<(std::ostream &output, const std::vector<T> &input) {
    std::cout << "[";

    for (auto it = input.begin(); it != input.end(); ++it)
        if (std::next(it) == input.end())
            std::cout << std::boolalpha << *it;
        else
            std::cout << *it << ",";

    std::cout << "]" << std::endl;

    return output;
}

class Solution {
public:
    int possibleStringCount(std::string word, int k) {
        int size = word.size();
        int cnt = 1;
        std::vector<int> groups;

        for (int index = 1; index < size; index++) {
            if (word[index - 1] == word[index]) {
                ++cnt;
            }
            else {
                groups.push_back(cnt);
                cnt = 1;
            }
        }

        groups.push_back(cnt);

        long long ans = 1;

        for (int g : groups) {
            ans = (ans * g) % mod;
        }

        if (k <= (int)groups.size())
            return ans;

        std::vector<int> dp(k, 0);
        dp[0] = 1;

        for (int num : groups) {
            std::vector<int> newDp(k, 0);
            long long sum = 0;
            for (int s = 0; s < k; ++s) {
                if (s > 0)
                    sum = (sum + dp[s - 1]) % mod;
                if (s > num)
                    sum = (sum - dp[s - num - 1] + mod) % mod;
                newDp[s] = sum;
            }
            dp = newDp;
        }

        long long invalid = 0;
        for (int s = groups.size(); s < k; ++s)
            invalid = (invalid + dp[s]) % mod;

        return (ans - invalid + mod) % mod;
    }

private:
    static int const mod = 1e9 + 7;
};

int main() {
    std::vector<TestSuit> testcase {
        { "aabbccdd", 7 },
        { "aabbccdd", 8 },
        { "aaabbb", 3 },
    };

    for (int i = 0; i < testcase.size(); i++) {
        Solution s;
        std::cout << ("\033[1;32mTestcase " + std::to_string(i + 1) + "\033[0m") << std::endl;
        auto r = s.possibleStringCount(testcase[i].word, testcase[i].k);
        std::cout << std::boolalpha << r << std::endl;
    }

    return 1;
}

//          foreground background
// black        30         40
// red          31         41
// green        32         42
// yellow       33         43
// blue         34         44
// magenta      35         45
// cyan         36         46
// white        37         47
