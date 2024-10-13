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
    if (input == false) {
        std::cout << "false\n";
    } else {
        std::cout << "true\n";
    }

    std::cout << std::endl;
    return output;
}

template <typename T>
std::ostream &operator<<(std::ostream &output, const int &input) {
    std::cout << input << std::endl;
    return output;
}

// TODO: Solve this shiet bro
class Solution {
    public:
        int minGroups(std::vector<std::vector<int>> &intervals) {
            std::vector<std::pair<int, int>> groupContainer;
            for (auto p : intervals) {
                groupContainer.push_back({p[0], 1});
                groupContainer.push_back({p[1] + 1, -1});
            }

            std::sort(groupContainer.begin(), groupContainer.end());
            int concurrentIntervals    = 0;
            int maxConcurrentIntervals = 0;
            for (auto g : groupContainer) {
                concurrentIntervals += g.second;
                maxConcurrentIntervals = std::max(maxConcurrentIntervals, concurrentIntervals);
            }

            return maxConcurrentIntervals;
        }
};

int main() {
    std::vector<std::vector<std::vector<int>>> input_s1 = {{{5, 10}, {6, 8}, {1, 5}, {2, 3}, {1, 10}}, {{1, 3}, {5, 6}, {8, 10}, {11, 13}}};
    std::vector<int> target_friend = {1, 0};

    for (int i = 0; i < input_s1.size(); i++) {
        Solution s;
        std::cout << ("\033[1;32mTestcase " + std::to_string(i + 1) + "\033[0m") << std::endl;
        auto r = s.minGroups(input_s1[i]);
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