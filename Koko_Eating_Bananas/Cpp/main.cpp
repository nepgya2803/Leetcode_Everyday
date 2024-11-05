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
        int minEatingSpeed(std::vector<int> &piles, int h)
        {
            int low    = 1;
            int max    = *std::max_element(piles.begin(), piles.end());
            int result = max;

            while (low <= max)
            {
                int k                 = (low + max) / 2;
                long long total_times = 0;

                for (auto pile : piles)
                {
                    total_times += std::ceil(static_cast<double>(pile) / k);
                }

                if (total_times <= h)
                {
                    result = k;
                    max    = k - 1;
                }
                else
                {
                    low = k + 1;
                }
            }

            return result;
        }
};

int main()
{
    std::vector<std::vector<int>> input = {
        {3, 6, 7, 11},
        {30, 11, 23, 4, 20},
        {30, 11, 23, 4, 20},
    };

    std::vector<int> h = {8, 5, 6};
    for (int i = 0; i < input.size(); i++)
    {
        Solution s;
        std::cout << ("\033[1;32mTestcase " + std::to_string(i + 1) + "\033[0m") << std::endl;
        auto r = s.minEatingSpeed(input[i], h[i]);
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
