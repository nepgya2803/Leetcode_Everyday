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
    long long maximumTripletValue(std::vector<int> &nums) {
        long long res = 0;
        int n = nums.size();
        std::vector<int> leftMax(n), rightMax(n);

        for (int index = 1; index < n; index++) {
            leftMax[index] = std::max(leftMax[index - 1], nums[index - 1]);
            rightMax[n - 1 - index] = std::max(rightMax[n - index], nums[n - index]);
        }

        for (int j = 1; j < n - 1; j++) {
            res = std::max(res, (long long)(leftMax[j] - nums[j]) * rightMax[j]);
        }

        return res;
    }
};

int main() {
    std::vector<TestSuit> testcase {
        { { 12, 6, 1, 2, 7 } },
        { { 1, 10, 3, 4, 19 } },
        { { 1, 2, 3 } },

    };

    for (int i = 0; i < testcase.size(); i++) {
        Solution s;
        std::cout << ("\033[1;32mTestcase " + std::to_string(i + 1) + "\033[0m") << std::endl;
        auto r = s.maximumTripletValue(testcase[i].nums);
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
