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
    int numOfSubarrays(std::vector<int> &arr) {
        const int MOD = 1e9 + 7;
        int count = 0;
        int oddCount = 0;
        int evenCount = 1;

        int currentSum = 0;
        for (int a : arr) {
            currentSum += a;

            if (currentSum % 2 == 0) {
                count += oddCount;
                evenCount++;
            }
            else {
                count += evenCount;
                oddCount++;
            }

            count %= MOD;
        }

        return count;
    }
};

int main() {
    std::vector<TestSuit> testcase {
        { { 1, 3, 5 } },
        { { 2, 4, 6 } },
        { { 1, 2, 3, 4, 5, 6, 7 } },
    };

    for (int i = 0; i < testcase.size(); i++) {
        Solution s;
        std::cout << ("\033[1;32mTestcase " + std::to_string(i + 1) + "\033[0m") << std::endl;
        auto r = s.numOfSubarrays(testcase[i].arr);
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
