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
        std::string s;
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
        int maximumLength(std::string s)
        {
            auto freq = std::unordered_map<std::string, int>();
            for (int start = 0; start < s.size(); start++)
            {
                std::string currString = "";
                for (int end = start; end < s.size(); end++)
                {
                    if (currString.empty() or currString.back() == s[end])
                    {
                        currString.push_back(s[end]);
                        freq[currString]++;
                    }
                    else
                    {
                        break;
                    }
                }
            }

            int max = -1;
            for (auto p : freq)
            {
                if (p.second >= 3)
                {
                    max = std::max(max, static_cast<int>(p.first.size()));
                }
            }

            return max;
        }
};

int main()
{
    std::vector<TestSuit> testcase {
        {"aaaa"},
        {"abcdef"},
        {"abcaba"},
    };

    for (int i = 0; i < testcase.size(); i++)
    {
        Solution s;
        std::cout << ("\033[1;32mTestcase " + std::to_string(i + 1) + "\033[0m") << std::endl;
        auto r = s.maximumLength(testcase[i].s);
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
