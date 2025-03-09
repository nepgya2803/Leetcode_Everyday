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
    std::vector<int> colors;
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
    int numberOfAlternatingGroups(std::vector<int> &colors, int k) {
        int group = 0;

        for (int i = 0; i < k - 1; i++) {
            colors.push_back(colors[i]);
        }

        int left = 0;
        int right = 1;
        int length = colors.size();

        while (right < length) {
            if (colors[right] == colors[right - 1]) {
                left = right;
                right++;
                continue;
            }

            right++;

            if (right - left < k)
                continue;

            group++;
            left++;
        }

        return group;
    }
};

int main() {
    std::vector<TestSuit> testcase {
        { { 0, 1, 0, 1, 0 }, 3 },
        { { 0, 1, 0, 0, 1, 0, 1 }, 6 },
        { { 1, 1, 0, 1 }, 4 },

    };

    for (int i = 0; i < testcase.size(); i++) {
        Solution s;
        std::cout << ("\033[1;32mTestcase " + std::to_string(i + 1) + "\033[0m") << std::endl;
        auto r = s.numberOfAlternatingGroups(testcase[i].colors, testcase[i].k);
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
