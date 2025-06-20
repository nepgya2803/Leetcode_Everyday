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
    std::string s;
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
    int maxDistance(std::string s, int k) {
        int max_distance = 0;
        int size = s.size();
        int x = 0, y = 0;
        int north = 0, south = 0, west = 0, east = 0;

        for (char it : s) {
            switch (it) {
                case 'N':
                    north++;
                    break;

                case 'S':
                    south++;
                    break;

                case 'W':
                    west++;
                    break;

                case 'E':
                    east++;
                    break;
            }

            int count_min1 = std::min({ north, south, k });
            int count_min2 = std::min({ east, west, k - count_min1 });
            max_distance = std::max(
                max_distance,
                calculate_mahattan(south, north, count_min1) + calculate_mahattan(west, east, count_min2));
        }

        return max_distance;
    }

private:
    int calculate_mahattan(int x, int y, int k) {
        return std::abs(x - y) + k * 2;
    }
};

int main() {
    std::vector<TestSuit> testcase {
        { "NWSE", 1 },
        { "NSWWEW", 3 },
    };

    for (int i = 0; i < testcase.size(); i++) {
        Solution s;
        std::cout << ("\033[1;32mTestcase " + std::to_string(i + 1) + "\033[0m") << std::endl;
        auto r = s.maxDistance(testcase[i].s, testcase[i].k);
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
