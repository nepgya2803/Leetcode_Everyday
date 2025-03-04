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
    std::vector<int> nums;
    int pivot;
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
    std::vector<int> pivotArray(std::vector<int> &nums, int pivot) {
        std::list<int> less;
        std::list<int> equal;
        std::list<int> greater;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < pivot) {
                less.push_back(nums[i]);
            }
            else if (nums[i] == pivot) {
                equal.push_back(nums[i]);
            }
            else {
                greater.push_back(nums[i]);
            }
        }

        less.insert(less.end(), equal.begin(), equal.end());
        less.insert(less.end(), greater.begin(), greater.end());

        std::vector<int> res;
        for (auto l : less) {
            res.push_back(l);
        }
        return res;
    }
};

int main() {
    std::vector<TestSuit> testcase {
        { { 9, 12, 5, 10, 14, 3, 10 }, 10 },
        { { -3, 4, 3, 2 }, 2 },
    };

    for (int i = 0; i < testcase.size(); i++) {
        Solution s;
        std::cout << ("\033[1;32mTestcase " + std::to_string(i + 1) + "\033[0m") << std::endl;
        auto r = s.pivotArray(testcase[i].nums, testcase[i].pivot);
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
