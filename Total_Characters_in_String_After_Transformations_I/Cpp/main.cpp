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
#include <list>

#define LOG_DEBUG(x) (std::cout << x << std::endl)

#define Assert(condition)

struct TestSuit {
public:
    std::string s;
    int t;
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
    int lengthAfterTransformations(std::string s, int t) {
        int nums[26] = { 0 };
        for (char ch : s)
            nums[ch - 'a']++;
        while (t--) {
            int cur[26] = { 0 };
            for (int j = 0; j < 26; j++) {
                if (j == 25 && nums[j] > 0) {
                    cur[0] = mod_add(cur[0], nums[j]);
                    cur[1] = mod_add(cur[1], nums[j]);
                }
                else {
                    if (j < 25)
                        cur[j + 1] = mod_add(cur[j + 1], nums[j]);
                }
            }
            for (int j = 0; j < 26; j++)
                nums[j] = cur[j];
        }
        int ans = 0;
        for (int i : nums)
            ans = mod_add(ans, i);
        return (int)ans;
    }

private:
    const int mod = 1e9 + 7;
    int mod_add(int a, int b) {
        a = a % mod;
        b = b % mod;
        return (((a + b) % mod) + mod) % mod;
    }
};

int main() {
    std::vector<TestSuit> testcase {
        { "abcyy", 2 },
        { "azbk", 1 },
    };

    for (int i = 0; i < testcase.size(); i++) {
        Solution s;
        std::cout << ("\033[1;32mTestcase " + std::to_string(i + 1) + "\033[0m") << std::endl;
        auto r = s.lengthAfterTransformations(testcase[i].s, testcase[i].t);
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
