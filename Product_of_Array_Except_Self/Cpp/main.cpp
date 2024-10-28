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
#include <vector>

template <typename T>
std::ostream &operator<<(std::ostream &output, const bool &input) {
    if (input) {
        std::cout << "false\n";
    } else {
        std::cout << "true\n";
    }

    std::cout << std::endl;
    return output;
}

template <typename T>
std::ostream &operator<<(std::ostream &output, const long long &input) {
    std::cout << input << std::endl;
    return output;
}

template <typename T>
std::ostream &operator<<(std::ostream &output, const std::vector<T> &input) {
    std::cout << "[";

    for (auto it = input.begin(); it != input.end(); ++it) {
        if (std::next(it) == input.end()) {
            std::cout << *it;
        } else {
            std::cout << *it << ",";
        }
    }

    std::cout << "]" << std::endl;

    return output;
}

// Division
class Solution {
    public:
        std::vector<int> productExceptSelf(std::vector<int> &nums) {
            std::vector<int> res(nums.size(), 0);
            int tmp       = 1;
            int zeroCount = false;
            std::for_each(nums.begin(), nums.end(), [&](const int &n) {
                if (n != 0)
                    tmp *= n;
                else
                    zeroCount++;
            });

            if (zeroCount > 0)
                return res;

            for (int i = 0; i < res.size(); i++) {
                if (zeroCount > 0)
                    res[i] = nums[i] == 0 ? tmp : 0;
                else
                    res[i] = tmp / nums[i];
            }

            return res;
        }
};

int main() {
    std::vector<std::vector<int>> input = {{1, 2, 3, 4}, {-1, 1, 0, -3, 3}};

    for (int i = 0; i < input.size(); i++) {
        Solution s;
        std::cout << ("\033[1;32mTestcase " + std::to_string(i + 1) + "\033[0m") << std::endl;
        auto r = s.productExceptSelf(input[i]);
        std::cout << r << std::endl;
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