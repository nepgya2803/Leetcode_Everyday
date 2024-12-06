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
        std::vector<int> banned;
        int n;
        int maxSum;
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
            std::cout << *it;
        else
            std::cout << *it << ",";

    std::cout << "]" << std::endl;

    return output;
}

class Solution
{
    public:
        int maxCount(std::vector<int> &banned, int n, int maxSum)
        {
            auto banSet = std::set<int>();
            auto res = std::set<int>();

            for (const int &ban : banned)
            {
                banSet.insert(ban);
            }

            int sum = 0;

            for (int i = 1; i <= n; i++)
            {
                if (banSet.find(i) == banSet.end() && sum + i <= maxSum)
                {
                    res.insert(i);
                    sum += i;
                }
            }

            return res.size();
        }
};

int main()
{
    std::vector<TestSuit> testcase {
        {{1, 6, 5},             5, 6 },
        {{1, 2, 3, 4, 5, 6, 7}, 8, 1 },
        {{11},                  7, 50},
    };

    for (int i = 0; i < testcase.size(); i++)
    {
        Solution s;
        std::cout << ("\033[1;32mTestcase " + std::to_string(i + 1) + "\033[0m") << std::endl;
        auto r = s.maxCount(testcase[i].banned, testcase[i].n, testcase[i].maxSum);
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
