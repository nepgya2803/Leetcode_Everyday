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
    std::vector<std::vector<int>> grid;
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
    std::vector<int> findMissingAndRepeatedValues(std::vector<std::vector<int>> &grid) {
        std::vector<int> result(2);
        int n = grid[0].size();
        std::unordered_map<int, int> umap;

        for (auto group : grid) {
            for (int i = 0; i < n; i++) {
                umap[group[i]]++;
                if (umap[group[i]] >= 2) {
                    result[0] = group[i];
                }
            }
        }

        for (int i = 1; i <= n * n; i++) {
            if (umap.find(i) == umap.end()) {
                result[1] = i;
                return result;
            }
        }

        return result;
    }
};

int main() {
    std::vector<TestSuit> testcase {
        { { { 1, 3 }, { 2, 2 } } },
        { { { 9, 1, 7 }, { 8, 9, 2 }, { 3, 4, 6 } } },
    };

    for (int i = 0; i < testcase.size(); i++) {
        Solution s;
        std::cout << ("\033[1;32mTestcase " + std::to_string(i + 1) + "\033[0m") << std::endl;
        auto r = s.findMissingAndRepeatedValues(testcase[i].grid);
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
