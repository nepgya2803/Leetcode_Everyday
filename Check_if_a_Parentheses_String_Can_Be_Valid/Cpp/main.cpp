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
        std::string s;
        std::string locked;
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
        bool canBeValid(std::string s, std::string locked)
        {
            int size = s.size();

            if (size % 2 == 1)
            {
                return false;
            }

            std::stack<int> openBracket;
            std::stack<int> unlocked;

            for (int i = 0; i < size; i++)
            {
                if (locked[i] == '0')
                {
                    unlocked.push(i);
                }
                else if (s[i] == '(')
                {
                    openBracket.push(i);
                }
                else if (s[i] == ')')
                {
                    if (!openBracket.empty())
                    {
                        openBracket.pop();
                    }
                    else if (!unlocked.empty())
                    {
                        unlocked.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
            }

            while (!openBracket.empty() && !unlocked.empty() &&
                   openBracket.top() < unlocked.top())
            {
                openBracket.pop();
                unlocked.pop();
            }

            if (!openBracket.empty())
            {
                return false;
            }

            return true;
        }
};

int main()
{
    std::vector<TestSuit> testcase {
        {"))()))", "010100"},
        {"()()",   "0000"  },
        {")",      "0"     },
    };

    for (int i = 0; i < testcase.size(); i++)
    {
        Solution s;
        std::cout << ("\033[1;32mTestcase " + std::to_string(i + 1) + "\033[0m") << std::endl;
        auto r = s.canBeValid(testcase[i].s, testcase[i].locked);
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
