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
        int minimumSubarrayLength(std::vector<int> &nums, int k)
        {
            std::vector<int> count(32, 0);
            int start = 0, end = 0, minLength = INT32_MAX;

            while (end < nums.size())
            {
                updateBits(count, nums[end], 1);
                while (start <= end && getVal(count) >= k)
                {
                    minLength = std::min(minLength, end - start + 1);
                    updateBits(count, nums[start], -1);
                    start++;
                }
                end++;
            }

            return minLength == INT32_MAX ? -1 : minLength;
        }

    private:
        void updateBits(std::vector<int> &count, int num, int val)
        {
            for (int i = 0; i < 32; i++)
            {
                if ((num >> i) & 1)
                {
                    count[i] += val;
                }
            }
        }

        int getVal(const std::vector<int> &count)
        {
            int ans = 0;
            for (int i = 0; i < 32; i++)
            {
                if (count[i] > 0)
                {
                    ans |= (1 << i);
                }
            }
            return ans;
        }
};

int main()
{
    std::vector<std::vector<int>> input = {
        {1, 2, 3},
        {2, 1, 8},
        {1, 2},
    };

    std::vector<int> k = {
        2,
        10,
        0,
    };

    for (int i = 0; i < input.size(); i++)
    {
        Solution s;
        std::cout << ("\033[1;32mTestcase " + std::to_string(i + 1) + "\033[0m") << std::endl;
        auto r = s.minimumSubarrayLength(input[i], k[i]);
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
