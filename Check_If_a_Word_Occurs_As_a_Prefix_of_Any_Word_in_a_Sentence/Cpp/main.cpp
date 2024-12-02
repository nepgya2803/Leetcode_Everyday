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
        int isPrefixOfWord(std::string sentence, std::string searchWord)
        {
            int numCount   = 0;
            int currentIdx = 0;
            int n          = sentence.size();
            int m          = searchWord.size();

            for (int i = 0; i < n; i++)
            {
                if (i == 0 || sentence[i - 1] == ' ')
                {
                    currentIdx++;
                    int p0 = i;
                    int p1 = 0;
                    while (p0 < n && p1 < m && sentence[p0] == searchWord[p1])
                    {
                        p0++;
                        p1++;
                    }
                    if (p1 == m)
                    {
                        return currentIdx;
                    }
                }
            }

            return -1;
        }
};

int main()
{
    std::vector<std::string> n = {
        "i love eating burger",
        "this problem is an easy problem",
        "i am tired",
    };

    std::vector<std::string> searchWords = {
        "burg",
        "pro",
        "you",
    };

    for (int i = 0; i < n.size(); i++)
    {
        Solution s;
        std::cout << ("\033[1;32mTestcase " + std::to_string(i + 1) + "\033[0m") << std::endl;
        auto r = s.isPrefixOfWord(n[i], searchWords[i]);
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
