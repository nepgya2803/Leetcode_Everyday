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
        long long maxMatrixSum(std::vector<std::vector<int>> &matrix)
        {
            long long sum     = 0;
            int minAbs        = INT32_MAX;
            int negativeCount = 0;

            for (auto const &row : matrix)
            {
                for (auto const &num : row)
                {
                    if (num < 0)
                    {
                        negativeCount++;
                    }
                    sum += std::abs(num);
                    minAbs = std::min(minAbs, std::abs(num));
                }
            }

            if (negativeCount % 2 == 1)
            {
                sum -= 2 * std::abs(minAbs);
            }

            return sum;
        }
};

int main()
{
    std::vector<std::vector<std::vector<int>>> testsets = {
        {
         {1, -1},
         {-1, 1},
         },
        {
         {1, 2, 3},
         {-1, -2, -3},
         {1, 2, 3},
         },
    };

    for (int i = 0; i < testsets.size(); i++)
    {
        Solution s;
        std::cout << ("\033[1;32mTestcase " + std::to_string(i + 1) + "\033[0m") << std::endl;
        auto r = s.maxMatrixSum(testsets[i]);
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
