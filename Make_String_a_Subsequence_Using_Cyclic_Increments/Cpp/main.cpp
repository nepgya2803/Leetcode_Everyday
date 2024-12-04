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

class Solution
{
    public:
        bool canMakeSubsequence(std::string str1, std::string str2)
        {
            int length1   = str1.size();
            int length2   = str2.size();
            int currIndex = 0;

            for (int i = 0; i < length1 && currIndex < length2; i++)
            {
                if (str2[currIndex] == str1[i] || str1[i] - 25 == str2[currIndex] || str1[i] + 1 == str2[currIndex])
                {
                    currIndex++;
                }
            }
            return currIndex == length2;
        }
};

int main()
{
    std::vector<std::pair<std::string, std::string>> testcase = {
        {"abc", "ad"},
        {"zc",  "ad"},
        {"ab",  "d" },
    };

    for (int i = 0; i < testcase.size(); i++)
    {
        Solution s;
        std::cout << ("\033[1;32mTestcase " + std::to_string(i + 1) + "\033[0m") << std::endl;
        auto r = s.canMakeSubsequence(testcase[i].first, testcase[i].second);
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
