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
        bool canSortArray(std::vector<int> &nums)
        {
            int prevMax = 0;
            int currMax = nums[0];
            int currMin = nums[0];
            int bit     = BitCount(nums[0]);

            for (int i = 1; i < nums.size(); i++)
            {
                int currBitCount = BitCount(nums[i]);

                if (bit == currBitCount)
                {
                    currMax = std::max(currMax, nums[i]);
                    currMin = std::min(currMin, nums[i]);
                }
                else
                {
                    if (prevMax > currMin)
                    {
                        return false;
                    }

                    prevMax = currMax;
                    bit     = BitCount(nums[i]);
                    currMax = nums[i];
                    currMin = nums[i];
                }
            }

            return currMin > prevMax;
        }

    private:
        int BitCount(int num)
        {
            return __builtin_popcount(num);
        }
};

int main()
{
    std::vector<std::vector<int>> input = {
        {8, 4,  2, 30, 15},
        {1, 2,  3, 4,  5 },
        {3, 16, 8, 4,  2 },
    };

    std::vector<int> h = {8, 5, 6};
    for (int i = 0; i < input.size(); i++)
    {
        Solution s;
        std::cout << ("\033[1;32mTestcase " + std::to_string(i + 1) + "\033[0m") << std::endl;
        auto r = s.canSortArray(input[i]);
        std::cout << std::boolalpha << (r ? true : false) << std::endl;
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
