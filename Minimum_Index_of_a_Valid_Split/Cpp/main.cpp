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
#include <functional>
#include <numeric>

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
    int minimumIndex(std::vector<int> &nums) {
        std::unordered_map<int, int> firstSplit, rightSplit;
        int n = nums.size();

        for (const int &num : nums) {
            rightSplit[num]++;
        }

        for (int index = 0; index < n; index++) {
            int num = nums[index];
            firstSplit[num]++;
            rightSplit[num]--;

            if (firstSplit[num] * 2 > index + 1 && rightSplit[num] * 2 > n - index - 1) {
                return index;
            }
        }

        return -1;
    }
};

int main() {
    std::vector<TestSuit> testcase {
        { { 1, 2, 2, 2 } },
        { { 2, 1, 3, 1, 1, 1, 7, 1, 2, 1 } },
        { { 3, 3, 3, 3, 7, 2, 2 } },
    };

    for (int i = 0; i < testcase.size(); i++) {
        Solution s;
        std::cout << ("\033[1;32mTestcase " + std::to_string(i + 1) + "\033[0m") << std::endl;
        auto r = s.minimumIndex(testcase[i].nums);
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
