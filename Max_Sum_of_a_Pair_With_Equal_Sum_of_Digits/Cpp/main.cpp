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
#include <unordered_set>
#include <vector>
#include <string_view>

#define LOG_DEBUG(x) (std::cout << x << std::endl)

#define Assert(condition)

struct TestSuit
{
    public:
        std::vector<int> nums;
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
        int maximumSum(std::vector<int> &nums)
        {
            std::unordered_map<int, std::priority_queue<int>> digitContainer;
            int size = nums.size();

            for (int i = 0; i < size; i++)
            {
                int digit = GetDigitFromString(nums[i]);
                digitContainer[digit].push(nums[i]);
            }

            int res = -1;

            for (auto pair : digitContainer)
            {
                std::priority_queue<int> sorted = pair.second;
                if (sorted.size() >= 2)
                {
                    int first = sorted.top();
                    sorted.pop();
                    int second = sorted.top();
                    res        = std::max(res, first + second);
                }
            }

            return res;
        }

    private:
        int GetDigitFromString(const int &origin)
        {
            int digit = 0;
            int temp  = origin;

            while (temp > 0)
            {
                auto [quot, remainder] = std::div(temp, 10);
                digit += remainder;
                temp = quot;
            }

            return digit;
        }
};

int main()
{
    std::vector<TestSuit> testcase {
        {{18, 43, 36, 13, 7}},
        {{10, 12, 19, 14}},
        {{999999999, 999999999}},
    };

    for (int i = 0; i < testcase.size(); i++)
    {
        Solution s;
        std::cout << ("\033[1;32mTestcase " + std::to_string(i + 1) + "\033[0m") << std::endl;
        auto r = s.maximumSum(testcase[i].nums);
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
