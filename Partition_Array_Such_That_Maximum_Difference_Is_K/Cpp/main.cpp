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
    int partitionArray(std::vector<int> &nums, int k) {
        int counted_array = 0;
        int size = nums.size();

        std::sort(nums.begin(), nums.end());

        int current_min = nums[0];

        for (int i = 0; i < size - 1; i++) {
            if (nums[i + 1] - current_min <= k)
                continue;
            else {
                counted_array++;
                current_min = nums[i + 1];
            }
        }

        if (nums[size - 1] - current_min <= k)
            counted_array++;

        return counted_array;
    }
};

int main() {
    std::vector<TestSuit> testcase {
        { { 3, 6, 1, 2, 5 }, 2 },
        { { 1, 2, 3 }, 1 },
        { { 2, 2, 4, 5 }, 0 },
    };

    for (int i = 0; i < testcase.size(); i++) {
        Solution s;
        std::cout << ("\033[1;32mTestcase " + std::to_string(i + 1) + "\033[0m") << std::endl;
        auto r = s.partitionArray(testcase[i].nums, testcase[i].k);
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
