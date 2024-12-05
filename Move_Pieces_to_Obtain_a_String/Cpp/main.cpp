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
        bool canChange(std::string start, std::string target)
        {
            int length = start.size();
            int p1 = 0;
            int p2 = 0;

            while (p1 < length || p2 < length)
            {
                while (p1 < length && start[p1] == '_')
                {
                    p1++;
                }

                while (p2 < length && target[p2] == '_')
                {
                    p2++;
                }

                if (p2 == length || p1 == length)
                {
                    return p2 == length && p1 == length;
                }

                if (start[p1] != target[p2] || (start[p1] == 'L' && p1 < p2) || (start[p1] == 'R' && p1 > p2))
                {
                    return false;
                }
                p1++, p2++;
            }

            return true;
        }
};

int main()
{
    std::vector<std::pair<std::string, std::string>> testcase = {
        {"_L__R__R_", "L______RR"},
        {"R_L_",      "__LR"     },
        {"_R",        "R_"       },
    };

    for (int i = 0; i < testcase.size(); i++)
    {
        Solution s;
        std::cout << ("\033[1;32mTestcase " + std::to_string(i + 1) + "\033[0m") << std::endl;
        auto r = s.canChange(testcase[i].first, testcase[i].second);
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
