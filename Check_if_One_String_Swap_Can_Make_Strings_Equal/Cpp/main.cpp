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
        bool areAlmostEqual(std::string s1, std::string s2)
        {
            int unmatchCount = 0;
            int size1        = s1.size();
            int size2        = s2.size();
            int x            = -1;

            for (int i = 0; i < size1; i++)
            {
                if (s1[i] != s2[i])
                {
                    if (x == -1)
                    {
                        x = i;
                    }
                    unmatchCount++;
                    if (unmatchCount == 2)
                    {
                        std::swap(s1[x], s1[i]);
                        break;
                    }
                }
            }

            return s1 == s2;
        }
};

int main()
{
    std::vector<TestSuit> testcase {
        {"bank",   "kanb"  },
        {"attack", "defend"},
        {"kelb",   "kelb"  },
    };

    for (int i = 0; i < testcase.size(); i++)
    {
        Solution s;
        std::cout << ("\033[1;32mTestcase " + std::to_string(i + 1) + "\033[0m") << std::endl;
        auto r = s.areAlmostEqual(testcase[i].s1, testcase[i].s2);
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
