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
#include <bits/stdc++.h>
#include <cstdlib>

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
        int largestCombination(std::vector<int> &candidates)
        {
            std::vector<int> containers(8 * sizeof(candidates[0]), 0);

            for (int i = 0; i < containers.size(); i++)
            {
                for (auto candidate : candidates)
                {
                    if ((candidate & (1 << i)) != 0)
                    {
                        containers[i]++;
                    }
                }
            }

            return *std::max_element(containers.begin(), containers.end());
        }
};

int main()
{
    std::vector<std::vector<int>> input = {
        {16, 17, 71, 62, 12, 24, 14},
        {8, 8},
    };

    for (int i = 0; i < input.size(); i++)
    {
        Solution s;
        std::cout << ("\033[1;32mTestcase " + std::to_string(i + 1) + "\033[0m") << std::endl;
        auto r = s.largestCombination(input[i]);
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
