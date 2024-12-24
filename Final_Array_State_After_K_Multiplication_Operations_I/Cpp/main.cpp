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

#define LOG_DEBUG(log, x) (std::cout << ("\033[1;32m" + log + ": " + x + "\033[0m") << std::endl)

struct TestSuit
{
    public:
        std::vector<int> nums;
        int k;
        int multiplier;
};

template <typename T> std::ostream &operator<<(std::ostream &output, const long long &input)
{
    std::cout << input << std::endl;
    return output;
}

template <typename T> std::ostream &operator<<(std::ostream &output, const std::vector<T> &input)
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
        std::vector<int> getFinalState(std::vector<int> &nums, int k, int multiplier)
        {
            auto res = std::vector<int>(nums.size(), 0);
            auto heapPrio = std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>>();
            for (int i = 0; i < nums.size(); i++)
            {
                heapPrio.push({nums[i], i});
            }

            while (k > 0)
            {
                auto tmp = heapPrio.top();
                LOG_DEBUG(tmp.first);
                tmp.first *= multiplier;
                heapPrio.pop();
                heapPrio.push(tmp);
                k--;
            }

            while (!heapPrio.empty())
            {
                auto tmp = heapPrio.top();
                heapPrio.pop();
                res[tmp.second] = tmp.first;
            }

            return res;
        }
};

int main()
{
    std::vector<TestSuit> testcase {
        {{2, 1, 3, 5, 6}, 5, 2},
        {{1, 2},          3, 4},
    };

    for (int i = 0; i < testcase.size(); i++)
    {
        Solution s;
        std::cout << ("\033[1;32mTestcase " + std::to_string(i + 1) + "\033[0m") << std::endl;
        auto r = s.getFinalState(testcase[i].nums, testcase[i].k, testcase[i].multiplier);
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
