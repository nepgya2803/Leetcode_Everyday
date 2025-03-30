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
#include <functional>
#include <numeric>

#define LOG_DEBUG(x) (std::cout << x << std::endl)

#define Assert(condition)

struct TestSuit {
public:
    std::string s;
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
    std::vector<int> partitionLabels(std::string s) {
        std::vector<int> partitionSize;
        int size = s.size();
        std::vector<int> lastOccurance(26, 0);

        for (int i = 0; i < size; ++i) {
            lastOccurance[s[i] - 'a'] = i;
        }

        int partStart = 0, partEnd = 0;
        for (int index = 0; index < size; ++index) {
            partEnd = std::max(partEnd, lastOccurance[s[index] - 'a']);

            if (index == partEnd) {
                partitionSize.push_back(index - partStart + 1);
                partStart = index + 1;
            }
        }

        return partitionSize;
    }
};

int main() {
    std::vector<TestSuit> testcase {
        { "ababcbacadefegdehijhklij" },
        { "eccbbbbdec" },
    };

    for (int i = 0; i < testcase.size(); i++) {
        Solution s;
        std::cout << ("\033[1;32mTestcase " + std::to_string(i + 1) + "\033[0m") << std::endl;
        auto r = s.partitionLabels(testcase[i].s);
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
