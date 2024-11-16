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
        std::vector<int> resultsArray(std::vector<int> &nums, int k)
        {
            int n     = nums.size();
            int left  = 0;
            int right = left + k - 1;
            std::vector<int> ans;

            while (right <= nums.size() - 1)
            {
                ans.push_back(CHECK(nums, left, right));
                left++;
                right++;
            }

            return ans;
        }

    private:
        int CHECK(std::vector<int> &nums, int left, int right)
        {
            int max = nums[right];
            for (; left < right;)
            {
                if (nums[right] - nums[right - 1] != 1)
                {
                    return -1;
                }
                else
                {
                    right--;
                }
            }

            return max;
        }
};

int main()
{
    std::vector<std::vector<int>> input = {
        {1, 2, 3, 4, 3, 2, 5},
        {2, 2, 2, 2, 2},
        {3, 2, 3, 2, 3, 2},
    };

    std::vector<int> k = {
        3,
        4,
        2,
    };

    for (int i = 0; i < input.size(); i++)
    {
        Solution s;
        std::cout << ("\033[1;32mTestcase " + std::to_string(i + 1) + "\033[0m") << std::endl;
        auto r = s.resultsArray(input[i], k[i]);
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
