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
    std::string s;
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
    int longestSubsequence(std::string s, int k) {
        int size = s.size();
        int zeros = 0, ones = 0;
        long long value = 0, pow = 1;

        for (char c : s) {
            if (c == '0') {
                zeros++;
            }
        }

        for (int index = size - 1; index >= 0; index--) {
            if (s[index] == '1') {
                if (value + pow > k) {
                    continue;
                }
                value += pow;
                ones++;
            }

            pow <<= 1;

            if (pow > k)
                break;
        }

        return zeros + ones;
    }
};

int main() {
    std::vector<TestSuit> testcase {
        { "1001010", 5 },
        { "00101001", 1 },
    };

    for (int i = 0; i < testcase.size(); i++) {
        Solution s;
        std::cout << ("\033[1;32mTestcase " + std::to_string(i + 1) + "\033[0m") << std::endl;
        auto r = s.longestSubsequence(testcase[i].s, testcase[i].k);
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
