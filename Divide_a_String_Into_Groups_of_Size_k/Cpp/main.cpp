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
    int k;
    char fill;
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
    std::vector<std::string> divideString(std::string s, int k, char fill) {
        int size = s.size();
        std::vector<std::string> res;

        for (int index = 0; index < size; index += k) {
            std::string sub = s.substr(index, k);
            res.emplace_back(sub);
        }

        if (res[res.size() - 1].size() < k) {
            while (res[res.size() - 1].size() < k) {
                res[res.size() - 1] += fill;
            }
        }

        return res;
    }
};

int main() {
    std::vector<TestSuit> testcase {
        { "abcdefghi", 3, 'x' },
        { "abcdefghij", 3, 'x' },
    };

    for (int i = 0; i < testcase.size(); i++) {
        Solution s;
        std::cout << ("\033[1;32mTestcase " + std::to_string(i + 1) + "\033[0m") << std::endl;
        auto r = s.divideString(testcase[i].s, testcase[i].k, testcase[i].fill);
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
