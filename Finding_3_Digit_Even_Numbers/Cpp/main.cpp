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
#include <climits>

#define LOG_DEBUG(x) (std::cout << x << std::endl)

#define Assert(condition)

struct TestSuit {
public:
    std::vector<int> digits;
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
    std::vector<int> findEvenNumbers(std::vector<int> &digits) {
        std::unordered_map<int, int> mp;
        std::vector<int> res;

        for (int d : digits) {
            mp[d]++;
        }

        for (int i = 100; i < 1000; i++) {
            if (i % 2 == 0) {
                int unit = i % 10;
                int ten = (i / 10) % 10;
                int hund = i / 100;

                mp[unit]--;
                mp[ten]--;
                mp[hund]--;

                if (mp[unit] >= 0 && mp[ten] >= 0 && mp[hund] >= 0) {
                    res.push_back(i);
                }

                mp[unit]++;
                mp[ten]++;
                mp[hund]++;
            }
        }

        return res;
    }
};

int main() {
    std::vector<TestSuit> testcase {
        { { 2, 1, 3, 0 } },
        { { 2, 2, 8, 8, 2 } },
        { { 3, 7, 5 } },
    };

    for (int i = 0; i < testcase.size(); i++) {
        Solution s;
        std::cout << ("\033[1;32mTestcase " + std::to_string(i + 1) + "\033[0m") << std::endl;
        auto r = s.findEvenNumbers(testcase[i].digits);
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
