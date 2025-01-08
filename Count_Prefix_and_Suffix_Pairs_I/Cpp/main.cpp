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
        std::vector<std::string> words;
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
        int countPrefixSuffixPairs(std::vector<std::string> &words)
        {
            int count = 0;
            for (int i = 0; i < words.size(); i++)
            {
                for (int j = i + 1; j < words.size(); j++)
                {
                    std::string word_1 = words[i];
                    std::string word_2 = words[j];

                    if (word_1.size() > word_2.size())
                    {
                        continue;
                    }

                    if (word_2.find(word_1) == 0 &&
                        word_2.rfind(word_1) == word_2.size() - word_1.size())
                    {
                        count++;
                    }
                }
            }

            return count;
        }
};

int main()
{
    std::vector<TestSuit> testcase {
        {{"a", "aba", "ababa", "aa"}},
        {{"pa", "papa", "ma", "mama"}},
        {{"abab", "ab"}},
    };

    for (int i = 0; i < testcase.size(); i++)
    {
        Solution s;
        std::cout << ("\033[1;32mTestcase " + std::to_string(i + 1) + "\033[0m") << std::endl;
        auto r = s.countPrefixSuffixPairs(testcase[i].words);
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
