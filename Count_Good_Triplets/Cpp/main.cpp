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
    std::vector<int> arr;
    int a;
    int b;
    int c;
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
    int countGoodTriplets(std::vector<int> &arr, int a, int b, int c) {
        int count = 0;
        int size = arr.size();

        for (int firstIndex = 0; firstIndex < size; firstIndex++) {
            for (int secondIndex = firstIndex + 1; secondIndex < size; secondIndex++) {
                for (int thirdIndex = secondIndex + 1; thirdIndex < size; thirdIndex++) {
                    bool first = std::abs(arr[firstIndex] - arr[secondIndex]) <= a ? true : false;
                    bool second = std::abs(arr[secondIndex] - arr[thirdIndex]) <= b ? true : false;
                    bool third = std::abs(arr[firstIndex] - arr[thirdIndex]) <= c ? true : false;

                    if (first && second && third)
                        count++;
                }
            }
        }

        return count;
    }
};

int main() {
    std::vector<TestSuit> testcase {
        { { 3, 0, 1, 1, 9, 7 }, 7, 2, 3 },
        { { 1, 1, 2, 2, 3 }, 0, 0, 1 },
    };

    for (int i = 0; i < testcase.size(); i++) {
        Solution s;
        std::cout << ("\033[1;32mTestcase " + std::to_string(i + 1) + "\033[0m") << std::endl;
        auto r = s.countGoodTriplets(testcase[i].arr, testcase[i].a, testcase[i].b, testcase[i].c);
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
