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
    std::string dominoes;
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
    std::string pushDominoes(std::string s) {
        s = 'L' + s + 'R';
        std::string res;

        int prev = 0;
        for (int curr = 1; curr < s.size(); ++curr) {
            if (s[curr] == '.') {
                continue;
            }

            int span = curr - prev - 1;
            if (prev > 0)
                res += s[prev];

            if (s[prev] == s[curr]) {
                res += std::string(span, s[prev]);
            }
            else if (s[prev] == 'L' && s[curr] == 'R') {
                res += std::string(span, '.');
            }
            else {
                res += std::string(span / 2, 'R') + std::string(span % 2, '.') + std::string(span / 2, 'L');
            }
            prev = curr;
        }
        return res;
    }
};

int main() {
    std::vector<TestSuit> testcase {
        { "RR.L" },
        { ".L.R...LR..L.." },
    };

    for (int i = 0; i < testcase.size(); i++) {
        Solution s;
        std::cout << ("\033[1;32mTestcase " + std::to_string(i + 1) + "\033[0m") << std::endl;
        auto r = s.pushDominoes(testcase[i].dominoes);
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
