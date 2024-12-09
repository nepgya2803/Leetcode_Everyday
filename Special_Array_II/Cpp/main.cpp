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

struct TestSuit
{
    public:
        std::vector<int> nums;
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
        std::vector<bool> isArraySpecial(std::vector<int> &nums, std::vector<std::vector<int>> &queries)
        {
            auto res     = std::vector<bool>(queries.size(), false);
            auto indices = std::vector<int>(nums.size(), 0);
            indices[0]   = 0;
            for (int i = 1; i < nums.size(); i++)
            {
                if (nums[i] % 2 == nums[i - 1] % 2)
                {
                    indices[i] = indices[i - 1] + 1;
                }
                else
                {
                    indices[i] = indices[i - 1];
                }
            }

            for (int i = 0; i < queries.size(); i++)
            {
                int start = queries[i][0];
                int end   = queries[i][1];
                res[i]    = indices[end] - indices[start] == 0;
            }

            return res;
        }
};

int main()
{
    std::vector<TestSuit> testcase {
        {
         {3, 4, 1, 2, 6},
         {{0, 4}},
         },
        {{4, 3, 1, 6},
         {
             {0, 2},
             {2, 3},
         }},
    };

    for (int i = 0; i < testcase.size(); i++)
    {
        Solution s;
        std::cout << ("\033[1;32mTestcase " + std::to_string(i + 1) + "\033[0m") << std::endl;
        auto r = s.isArraySpecial(testcase[i].nums, testcase[i].queries);
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
