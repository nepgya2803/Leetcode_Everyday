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

#define LOG_DEBUG(x) (std::cout << x << std::endl)

#define Assert(condition)

struct TestSuit
{
    public:
        std::vector<int> nums;
        int k;
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
        int total_way = 0;

        int findTargetSumWays(std::vector<int> &nums, int target)
        {
            CalculateWay(nums, target, 0, 0);
            return total_way;
        }

    private:
        void CalculateWay(std::vector<int> &nums, int target, int currentIndex, int currentSum)
        {
            if (currentIndex == nums.size())
            {
                if (currentSum == target)
                {
                    total_way++;
                }
            }
            else
            {
                CalculateWay(nums, target, currentIndex + 1, currentSum + nums[currentIndex]);
                CalculateWay(nums, target, currentIndex + 1, currentSum - nums[currentIndex]);
            }
        }
};

int main()
{
    std::vector<TestSuit> testcase {
        {{1, 1, 1, 1, 1}, 3},
        {{1},             1},
    };

    for (int i = 0; i < testcase.size(); i++)
    {
        Solution s;
        std::cout << ("\033[1;32mTestcase " + std::to_string(i + 1) + "\033[0m") << std::endl;
        auto r = s.findTargetSumWays(testcase[i].nums, testcase[i].k);
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
