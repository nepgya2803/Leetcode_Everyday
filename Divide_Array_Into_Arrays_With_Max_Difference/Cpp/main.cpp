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
    std::vector<int> nums;
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
    std::vector<std::vector<int>> divideArray(std::vector<int> &nums, int k) {
        std::vector<std::vector<int>> result {};

        std::sort(nums.begin(), nums.end());
        int size = nums.size();

        for (int i = 0; i < size - 2; i += 3) {
            int first = nums[i];
            int second = nums[i + 1];
            int third = nums[i + 2];

            if (second - first <= k && third - second <= k && third - first <= k)
                result.push_back({ first, second, third });
            else {
                return {};
            }
        }

        return result;
    }
};

int main() {
    std::vector<TestSuit> testcase {
        { { 1, 3, 4, 8, 7, 9, 3, 5, 1 }, 2 },
        { { 2, 4, 2, 2, 5, 2 }, 2 },
        { { 4, 2, 9, 8, 2, 12, 7, 12, 10, 5, 8, 5, 5, 7, 9, 2, 5, 11 }, 14 },
    };

    for (int i = 0; i < testcase.size(); i++) {
        Solution s;
        std::cout << ("\033[1;32mTestcase " + std::to_string(i + 1) + "\033[0m") << std::endl;
        auto r = s.divideArray(testcase[i].nums, testcase[i].k);
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
