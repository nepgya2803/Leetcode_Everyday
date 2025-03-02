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
    std::vector<std::vector<int>> nums1;
    std::vector<std::vector<int>> nums2;
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
    std::vector<std::vector<int>> mergeArrays(std::vector<std::vector<int>> &nums1,
                                              std::vector<std::vector<int>> &nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        int p1 = 0;
        int p2 = 0;
        std::vector<std::vector<int>> mergeArray;

        for (; p1 < size1 && p2 < size2;) {
            if (nums1[p1][0] == nums2[p2][0]) {
                mergeArray.push_back({ nums1[p1][0], nums1[p1][1] + nums2[p2][1] });
                p1++;
                p2++;
            }
            else if (nums1[p1][0] < nums2[p2][0]) {
                mergeArray.push_back({ nums1[p1][0], nums1[p1][1] });
                p1++;
            }
            else {
                mergeArray.push_back({ nums2[p2][0], nums2[p2][1] });
                p2++;
            }
        }

        while (p1 < size1) {
            mergeArray.push_back(nums1[p1]);
            p1++;
        }

        while (p2 < size2) {
            mergeArray.push_back(nums2[p2]);
            p2++;
        }

        return mergeArray;
    }
};

int main() {
    std::vector<TestSuit> testcase {
        {
            { { 1, 2 }, { 2, 3 }, { 4, 5 } },
            { { 1, 4 }, { 3, 2 }, { 4, 1 } },
        },
        {
            { { 2, 4 }, { 3, 6 }, { 5, 5 } },
            { { 1, 3 }, { 4, 3 } },
        },
    };

    for (int i = 0; i < testcase.size(); i++) {
        Solution s;
        std::cout << ("\033[1;32mTestcase " + std::to_string(i + 1) + "\033[0m") << std::endl;
        auto r = s.mergeArrays(testcase[i].nums1, testcase[i].nums2);
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
