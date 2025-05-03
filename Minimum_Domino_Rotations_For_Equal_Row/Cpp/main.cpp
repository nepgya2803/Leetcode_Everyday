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
#include <climits>

#define LOG_DEBUG(x) (std::cout << x << std::endl)

#define Assert(condition)

struct TestSuit {
public:
    std::vector<int> tops;
    std::vector<int> bottoms;
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
    int minDominoRotations(std::vector<int> &tops, std::vector<int> &bottoms) {
        int res = INT_MAX;

        int face[7] = {};
        for (int i = 0; i < tops.size(); i++) {
            face[tops[i]]++;
            if (bottoms[i] != tops[i])
                face[bottoms[i]]++;
        }

        // for each possible face from 1...6
        for (int x = 1; x <= 6; x++) {
            if (face[x] < tops.size())
                continue; // can't fill entire row

            int maintainTop = 0, maintainBottom = 0;
            bool possible = true;

            // count flips
            for (int i = 0; i < tops.size(); i++) {
                if (tops[i] != x && bottoms[i] != x) {
                    possible = false;
                    break;
                }
                if (tops[i] != x)
                    maintainTop++;
                if (bottoms[i] != x)
                    maintainBottom++;
            }

            if (possible)
                res = std::min(res, std::min(maintainTop, maintainBottom));
        }

        return res == INT_MAX ? -1 : res;
    }
};

int main() {
    std::vector<TestSuit> testcase {
        { { 2, 1, 2, 4, 2, 2 }, { 5, 2, 6, 2, 3, 2 } },
        { { 3, 5, 1, 2, 3 }, { 3, 6, 3, 3, 4 } },
    };

    for (int i = 0; i < testcase.size(); i++) {
        Solution s;
        std::cout << ("\033[1;32mTestcase " + std::to_string(i + 1) + "\033[0m") << std::endl;
        auto r = s.minDominoRotations(testcase[i].tops, testcase[i].bottoms);
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
