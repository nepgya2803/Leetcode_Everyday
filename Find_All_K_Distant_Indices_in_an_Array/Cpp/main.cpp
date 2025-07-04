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
    int key;
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
    std::vector<int> findKDistantIndices(std::vector<int> &nums, int key, int k) {
        std::vector<int> ans;
        int size = nums.size();
        int r = 0;

        for (int j = 0; j < size; j++) {
            if (nums[j] == key) {
                int l = std::max(r, j - k);
                r = std::min(size - 1, j + k) + 1;

                for (int index = l; index < r; index++) {
                    ans.emplace_back(index);
                }
            }
        }

        return ans;
    }
};

int main() {
    std::vector<TestSuit> testcase {
        { { 3, 4, 9, 1, 3, 9, 5 }, 9, 1 },
        { { 2, 2, 2, 2, 2 }, 2, 2 },
    };

    for (int i = 0; i < testcase.size(); i++) {
        Solution s;
        std::cout << ("\033[1;32mTestcase " + std::to_string(i + 1) + "\033[0m") << std::endl;
        auto r = s.findKDistantIndices(testcase[i].nums, testcase[i].key, testcase[i].k);
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
