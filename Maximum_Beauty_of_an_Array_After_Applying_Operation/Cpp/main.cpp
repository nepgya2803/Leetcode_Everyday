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
        int maximumBeauty(std::vector<int> &nums, int k)
        {
            int maxBeauty = 0;
            std::sort(nums.begin(), nums.end());
            int right = 0;
            
            for (int left = 0; left < nums.size(); left++)
            {
                while (right < nums.size() && nums[right] - nums[left] <= 2 * k)
                {
                    right++;
                }
                maxBeauty = std::max(maxBeauty, right - left);
            }

            return maxBeauty;
        }
};

int main()
{
    std::vector<TestSuit> testcase {
        {{4, 6, 1, 2}, 2 },
        {{1, 1, 1, 1}, 10},
    };

    for (int i = 0; i < testcase.size(); i++)
    {
        Solution s;
        std::cout << ("\033[1;32mTestcase " + std::to_string(i + 1) + "\033[0m") << std::endl;
        auto r = s.maximumBeauty(testcase[i].nums, testcase[i].k);
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
