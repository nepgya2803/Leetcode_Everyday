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
        long long countFairPairs(std::vector<int> &nums, int lower, int upper)
        {
            int n         = nums.size();
            long long ans = 0;
            // Sorting the array
            std::sort(nums.begin(), nums.end());
            std::cout << nums << std::endl;
            for (int i = 0; i < nums.size(); i++)
            {
                auto up = std::upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]);
                auto low = std::lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]);
                ans += (up - low);
                std::cout << std::distance(nums.begin(), up) << std::setw(2) << std::distance(nums.begin(), low) << std::setw(2) << ans << std::endl;
            }

            return ans;
        }
};

int main()
{
    std::vector<std::vector<int>> input = {
        {0, 1, 7, 4, 4, 5},
        {1, 7, 9, 2, 5},
    };

    std::vector<int> lower = {3, 11};

    std::vector<int> upper = {6, 11};

    for (int i = 0; i < input.size(); i++)
    {
        Solution s;
        std::cout << ("\033[1;32mTestcase " + std::to_string(i + 1) + "\033[0m") << std::endl;
        auto r = s.countFairPairs(input[i], lower[i], upper[i]);
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
