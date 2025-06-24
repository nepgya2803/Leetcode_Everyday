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
    std::vector<int> nums1;
    std::vector<int> nums2;
    long long k;
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
    long long kthSmallestProduct(std::vector<int> &nums1, std::vector<int> &nums2, long long k) {
        long long left = -1e10, right = 1e10;

        while (left < right) {
            long long mid = left + (right - left) / 2;
            if (countProduct(nums1, nums2, mid) < k) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }

        return left;
    }

private:
    long long countProduct(std::vector<int> &nums1, std::vector<int> &nums2, long long target) {
        long long count = 0;

        for (int num1 : nums1) {
            if (num1 == 0) {
                if (target >= 0)
                    count += nums2.size();
                continue;
            }

            int low = 0, high = nums2.size();
            while (low < high) {
                int mid = low + (high - low) / 2;
                long product = (long)num1 * nums2[mid];
                if (product <= target) {
                    if (num1 > 0)
                        low = mid + 1;
                    else
                        high = mid;
                }
                else {
                    if (num1 > 0)
                        high = mid;
                    else
                        low = mid + 1;
                }
            }

            count += (num1 > 0) ? low : nums2.size() - low;
        }

        return count;
    }
};

int main() {
    std::vector<TestSuit> testcase {
        {
            { 2, 5 },
            { 3, 4 },
            2,
        },
        {
            { -4, -2, 0, 3 },
            { 2, 4 },
            6,
        },
        {
            { -2, -1, 0, 1, 2 },
            { -3, -1, 2, 4, 5 },
            3,
        },
    };

    for (int i = 0; i < testcase.size(); i++) {
        Solution s;
        std::cout << ("\033[1;32mTestcase " + std::to_string(i + 1) + "\033[0m") << std::endl;
        auto r = s.kthSmallestProduct(testcase[i].nums1, testcase[i].nums2, testcase[i].k);
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
