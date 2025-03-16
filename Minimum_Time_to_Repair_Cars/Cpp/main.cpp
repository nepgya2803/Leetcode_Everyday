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
    std::vector<int> ranks;
    int cars;
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
    long long repairCars(std::vector<int> &ranks, int cars) {
        int lowRank = *std::min_element(ranks.begin(), ranks.end());
        int maxRank = *std::max_element(ranks.begin(), ranks.end());

        std::vector<int> freq(maxRank + 1);

        for (int rank : ranks) {
            lowRank = std::min(rank, lowRank);
            freq[rank]++;
        }

        long long low = 1;
        long long high = 1LL * lowRank * cars * cars;

        while (low < high) {
            long long midTime = (low + high) / 2;
            long long carRepaired = 0;

            for (int i = 1; i <= maxRank; i++) {
                carRepaired += freq[i] * (long long)std::sqrt(midTime / (long long)i);
            }

            if (carRepaired >= cars) {
                high = midTime;
            }
            else {
                low = midTime + 1;
            }
        }

        return low;
    }
};

int main() {
    std::vector<TestSuit> testcase {
        { { 4, 2, 3, 1 }, 10 },
        { { 5, 1, 8 }, 6 },
    };

    for (int i = 0; i < testcase.size(); i++) {
        Solution s;
        std::cout << ("\033[1;32mTestcase " + std::to_string(i + 1) + "\033[0m") << std::endl;
        auto r = s.repairCars(testcase[i].ranks, testcase[i].cars);
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
