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
        std::string s1;
        std::string s2;
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
        bool buddyStrings(std::string s, std::string goal)
        {
            int size = s.size();
            int x    = -1;

            if (goal.size() != size)
                return false;

            if (goal == s)
            {
                std::set<char> tmp(s.begin(), s.end());
                return tmp.size() < goal.size();
            }

            for (int i = 0; i < size; i++)
            {
                if (s[i] != goal[i])
                {
                    if (x == -1)
                    {
                        x = i;
                    }
                    else
                    {
                        std::swap(s[x], s[i]);
                        return s == goal;
                    }
                }
            }
            return false;
        }
};

int main()
{
    std::vector<TestSuit> testcase {
        {"ab", "ba"},
        {"ab", "ab"},
        {"aa", "aa"},
    };

    for (int i = 0; i < testcase.size(); i++)
    {
        Solution s;
        std::cout << ("\033[1;32mTestcase " + std::to_string(i + 1) + "\033[0m") << std::endl;
        auto r = s.buddyStrings(testcase[i].s1, testcase[i].s2);
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
