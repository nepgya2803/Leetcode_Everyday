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
#include <unordered_set>

struct TestSuit
{
    public:
        std::vector<std::vector<int>> events;
};

template <typename T>
std::ostream &operator<<(std::ostream &output, const long long &input)
{
    std::cout << input << std::endl;
    return output;
}

template <typename T>
std::ostream &operator<<(std::ostream &output, const std::vector<T> &input)
{
    std::cout << "[";

    for (auto it = input.begin(); it != input.end(); ++it)
        if (std::next(it) == input.end())
            std::cout << *it;
        else
            std::cout << *it << ",";

    std::cout << "]" << std::endl;

    return output;
}

class Solution
{
    public:
        int maxTwoEvents(std::vector<std::vector<int>> &events)
        {
            auto storage = std::vector<std::array<int, 3>>();

            for (auto const &event : events)
            {
                storage.push_back({event[0], 1, event[2]});
                storage.push_back({event[1] + 1, 0, event[2]});
            }

            int ans      = 0;
            int maxValue = 0;

            std::sort(storage.begin(), storage.end());

            for (auto s : storage)
            {
                if (s[1])
                {
                    ans = std::max(ans, s[2] + maxValue);
                }
                else
                {
                    maxValue = std::max(maxValue, s[2]);
                }
            }

            return ans;
        }
};

int main()
{
    std::vector<TestSuit> testcase {
        {{
            {1, 3, 2},
            {4, 5, 2},
            {2, 4, 3},
        }},
        {{
            {1, 3, 2},
            {4, 5, 2},
            {1, 5, 5},
        }},
        {{
            {1, 5, 3},
            {1, 5, 1},
            {6, 6, 5},
        }},
    };

    for (int i = 0; i < testcase.size(); i++)
    {
        Solution s;
        std::cout << ("\033[1;32mTestcase " + std::to_string(i + 1) + "\033[0m") << std::endl;
        auto r = s.maxTwoEvents(testcase[i].events);
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
