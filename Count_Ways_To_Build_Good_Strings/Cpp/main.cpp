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
        int low;
        int high;
        int zero;
        int one;
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
        int countGoodStrings(int low, int high, int zero, int one)
        {
            if (zero > one)
            {
                return countGoodStrings(low, high, one, zero);
            }

            std::vector<int> dp(high + 1, 0);
            dp[0]   = 1;
            int res = 0;

            for (int i = 1; i <= high; i++)
            {
                if (i >= zero)
                {
                    dp[i] = (dp[i] + dp[i - zero]) % MOD;
                }

                if (i >= one)
                {
                    dp[i] = (dp[i] + dp[i - one]) % MOD;
                }

                if (i >= low)
                {
                    res = (res + dp[i]) % MOD;
                }
            }

            return res;
        }

    private:
        int MOD = 1e9 + 7;
};

int main()
{
    std::vector<TestSuit> testcase {
        {3, 3, 1, 1},
        {2, 3, 1, 2},
    };

    for (int i = 0; i < testcase.size(); i++)
    {
        Solution s;
        std::cout << ("\033[1;32mTestcase " + std::to_string(i + 1) + "\033[0m") << std::endl;
        auto r = s.countGoodStrings(testcase[i].low, testcase[i].high,
                                    testcase[i].zero, testcase[i].one);
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
