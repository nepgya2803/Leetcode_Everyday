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
        long long maximumSubarraySum(std::vector<int> &nums, int k)
        {
            int max         = 0;
            int begin       = 0;
            auto numtoIndex = std::unordered_set<int>();
            int sum         = 0;
            for (int end = 0; end < nums.size(); end++)
            {
                if (numtoIndex.find(nums[end]) == numtoIndex.end())
                {
                    sum += nums[end];
                    numtoIndex.insert(nums[end]);

                    if (end - begin + 1 == k)
                    {
                        max = std::max(max, sum);
                        sum -= nums[begin];
                        numtoIndex.erase(nums[begin]);
                        begin++;
                    }
                }
                else
                {
                    while (nums[begin] != nums[end])
                    {
                        sum -= nums[begin];
                        numtoIndex.erase(nums[begin]);
                        begin++;
                    }
                    begin++;
                }
            }

            return max;
        }
};

int main()
{
    std::vector<std::vector<int>> input = {
        {1, 5, 4, 2, 9, 9, 9},
        {4, 4, 4},
    };

    std::vector<int> k = {
        3,
        3,
    };

    for (int i = 0; i < input.size(); i++)
    {
        Solution s;
        std::cout << ("\033[1;32mTestcase " + std::to_string(i + 1) + "\033[0m") << std::endl;
        auto r = s.maximumSubarraySum(input[i], k[i]);
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
