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

#define ll long long
class Solution
{
    public:
        int shortestSubarray(std::vector<int> &nums, int k)
        {
            int n     = nums.size();
            auto dq   = std::deque<std::pair<ll, int>>();
            ll curSum = 0;
            int ans   = INT32_MAX;

            for (int i = 0; i < n; i++)
            {
                curSum += nums[i];

                if (curSum >= k)
                {
                    ans = std::min(ans, i + 1);
                }

                while (!dq.empty() && curSum - dq.front().first >= k)
                {
                    auto [prefix, endIdx] = dq.front();
                    dq.pop_front();
                    ans = std::min(ans, i - endIdx);
                }

                while (!dq.empty() && dq.back().first > curSum)
                {
                    dq.pop_back();
                }

                dq.push_back({curSum, i});
            }

            return ans == INT32_MAX ? -1 : ans;
        }
};

int main()
{
    std::vector<std::vector<int>> input = {
        {1},
        {1, 2},
        {2, -1, 2},
    };

    std::vector<int> k = {
        1,
        4,
        3,
    };

    for (int i = 0; i < input.size(); i++)
    {
        Solution s;
        std::cout << ("\033[1;32mTestcase " + std::to_string(i + 1) + "\033[0m") << std::endl;
        auto r = s.shortestSubarray(input[i], k[i]);
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
