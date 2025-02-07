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

struct TestSuit
{
    public:
        int limit;
        std::vector<std::vector<int>> queries;
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
            std::cout << std::boolalpha << *it;
        else
            std::cout << *it << ",";

    std::cout << "]" << std::endl;

    return output;
}

class Solution
{
    public:
        std::vector<int> queryResults(int limit, std::vector<std::vector<int>> &queries)
        {
            int size = queries.size();
            std::unordered_map<int, int> distinctColor;
            std::unordered_map<int, int> ballMap;
            std::vector<int> result(size, 0);

            for (int i = 0; i < size; i++)
            {
                int ball  = queries[i][0];
                int color = queries[i][1];

                if (ballMap.find(ball) != ballMap.end())
                {
                    int prevColor = ballMap[ball];
                    distinctColor[prevColor]--;

                    if (distinctColor[prevColor] == 0)
                        distinctColor.erase(prevColor);
                }

                ballMap[ball] = color;
                distinctColor[color]++;
                result[i] = distinctColor.size();
            }

            return result;
        }
};

int main()
{
    std::vector<TestSuit> testcase {
        {4, {{1, 4}, {2, 5}, {1, 3}, {3, 4}}        },
        {4, {{0, 1}, {1, 2}, {2, 2}, {3, 4}, {4, 5}}},
    };

    for (int i = 0; i < testcase.size(); i++)
    {
        Solution s;
        std::cout << ("\033[1;32mTestcase " + std::to_string(i + 1) + "\033[0m") << std::endl;
        auto r = s.queryResults(testcase[i].limit, testcase[i].queries);
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
