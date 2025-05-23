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
        int findChampion(int n, std::vector<std::vector<int>> &edges)
        {
            std::vector<int> indirect(n, 0);

            for (auto const &edge : edges)
            {
                indirect[edge[1]]++;
            }

            int champ = -1, champCount = 0;

            for (int i = 0; i < indirect.size(); i++)
            {
                if (indirect[i] == 0)
                {
                    champCount++;
                    champ = i;
                }
            }

            return champCount > 1 ? -1 : champ;
        }
};

int main()
{
    std::vector<int> n {
        3,
        4,
    };

    std::vector<std::vector<std::vector<int>>> testsets = {
        {{0, 1}, {1, 2}},
        {{0, 2}, {1, 3}, {1, 2}},
    };

    for (int i = 0; i < testsets.size(); i++)
    {
        Solution s;
        std::cout << ("\033[1;32mTestcase " + std::to_string(i + 1) + "\033[0m") << std::endl;
        auto r = s.findChampion(n[i], testsets[i]);
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
