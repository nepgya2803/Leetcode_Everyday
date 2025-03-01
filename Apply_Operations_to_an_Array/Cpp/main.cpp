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
    std::vector<int> arr;
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
    std::vector<int> applyOperations(std::vector<int> &nums) {
        int size = nums.size();
        int writeIndex = 0;

        for (int i = 0; i < size; i++) {
            int tmp = nums[i];

            if (i < size - 1 && nums[i] == nums[i + 1]) {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }

            if (nums[i] != 0) {
                if (i != writeIndex) {
                    std::swap(nums[i], nums[writeIndex]);
                }
                writeIndex++;
            }
        }

        return nums;
    }
};

int main() {
    std::vector<TestSuit> testcase {
        { { 1, 2, 2, 1, 1, 0 } },
        { { 0, 1 } },
    };

    for (int i = 0; i < testcase.size(); i++) {
        Solution s;
        std::cout << ("\033[1;32mTestcase " + std::to_string(i + 1) + "\033[0m") << std::endl;
        auto r = s.applyOperations(testcase[i].arr);
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
