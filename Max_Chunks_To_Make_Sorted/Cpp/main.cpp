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

struct TestSuit
{
    public:
        std::vector<int> arr;
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
        int maxChunksToSorted(std::vector<int> &arr)
        {
            int n = arr.size();
            std::stack<int> stk;

            for (int i = 0; i < n; i++)
            {
                if (stk.empty() || arr[i] > stk.top())
                {
                    stk.push(arr[i]);
                }
                else
                {
                    int maxEle = stk.top();
                    while (!stk.empty() && arr[i] < stk.top())
                    {
                        stk.pop();
                    }
                    stk.push(maxEle);
                }
            }

            return stk.size();
        }
};

int main()
{
    std::vector<TestSuit> testcase {
        {{4, 3, 2, 1, 0}},
        {{1, 0, 2, 3, 4}},
    };

    for (int i = 0; i < testcase.size(); i++)
    {
        Solution s;
        std::cout << ("\033[1;32mTestcase " + std::to_string(i + 1) + "\033[0m") << std::endl;
        auto r = s.maxChunksToSorted(testcase[i].arr);
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
