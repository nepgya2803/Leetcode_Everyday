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
    std::vector<std::vector<int>> queries;
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
    int minZeroArray(std::vector<int> &nums, std::vector<std::vector<int>> &queries) {
        int n = nums.size(), left = 0, right = queries.size();

        if (!canFormZeroArray(nums, queries, right))
            return -1;

        while (left <= right) {
            int middle = left + (right - left) / 2;
            if (canFormZeroArray(nums, queries, middle)) {
                right = middle - 1;
            }
            else {
                left = middle + 1;
            }
        }

        return left;
    }

private:
    bool canFormZeroArray(std::vector<int> &nums, std::vector<std::vector<int>> &queries, int k) {
        int n = nums.size(), sum = 0;
        std::vector<int> differenceArray(n + 1);

        for (int queryIndex = 0; queryIndex < k; queryIndex++) {
            int start = queries[queryIndex][0], end = queries[queryIndex][1], val = queries[queryIndex][2];

            differenceArray[start] += val;
            differenceArray[end + 1] -= val;
        }

        for (int numIndex = 0; numIndex < n; numIndex++) {
            sum += differenceArray[numIndex];
            if (sum < nums[numIndex])
                return false;
        }
        return true;
    }
};

int main() {
    std::vector<TestSuit> testcase {
        {
            { 2, 0, 2 },
            {
                { 0, 2, 1 },
                { 0, 2, 1 },
                { 1, 1, 3 },
            },
        },
        {
            { 4, 3, 2, 1 },
            {
                { 1, 3, 2 },
                { 0, 2, 1 },
            },
        },
    };

    for (int i = 0; i < testcase.size(); i++) {
        Solution s;
        std::cout << ("\033[1;32mTestcase " + std::to_string(i + 1) + "\033[0m") << std::endl;
        auto r = s.minZeroArray(testcase[i].nums, testcase[i].queries);
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
