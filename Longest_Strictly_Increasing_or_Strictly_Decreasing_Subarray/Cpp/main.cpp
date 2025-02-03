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
        int longestMonotonicSubarray(std::vector<int> &nums)
        {
            int size = nums.size();

            if (size <= 1)
                return size;

            int inc = 1;
            int des = 1;
            int max = 0;

            for (int i = 0; i < size - 1; i++)
            {
                if (nums[i + 1] > nums[i])
                {
                    inc++;
                    des = 1;
                }
                if (nums[i + 1] < nums[i])
                {
                    des++;
                    inc = 1;
                }
                else
                {
                    inc = 1;
                    des = 1;
                }

                max = std::max(max, (inc > des ? inc : des));
            }

            return max;
        }
};

int main()
{
    std::vector<TestSuit> testcase {
        {{1, 4, 3, 3, 2}},
        {{3, 3, 3, 3}},
        {{3, 2, 1}},
    };

    for (int i = 0; i < testcase.size(); i++)
    {
        Solution s;
        std::cout << ("\033[1;32mTestcase " + std::to_string(i + 1) + "\033[0m") << std::endl;
        auto r = s.longestMonotonicSubarray(testcase[i].nums);
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
