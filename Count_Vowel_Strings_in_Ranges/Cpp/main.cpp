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
        std::vector<std::string> words;
        std::vector<std::vector<int>> queries;
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
        std::vector<int> vowelStrings(std::vector<std::string> &words, std::vector<std::vector<int>> &queries)
        {
            std::set<char> vowelSet = {'a', 'e', 'i', 'o', 'u'};
            std::vector<int> prefix(words.size());
            std::vector<int> res;
            int sum = 0;

            for (int i = 0; i < words.size(); i++)
            {
                std::string current_word = words[i];
                if (vowelSet.count(current_word[0]) && vowelSet.count(current_word[current_word.size() - 1]))
                {
                    sum++;
                }
                prefix[i] = sum;
            }

            for (int i = 0; i < queries.size(); i++)
            {
                std::vector<int> querry = queries[i];
                int result = prefix[querry[1]] - (querry[0] == 0 ? 0 : prefix[querry[0] - 1]);
                res.push_back(result);
            }

            return res;
        }
};

int main()
{
    std::vector<TestSuit> testcase {
        {{"aba", "bcb", "ece", "aa", "e"},
         {
             {0, 2},
             {1, 4},
             {1, 1},
         }},
        {{"a", "e", "i"},
         {
             {0, 2},
             {0, 1},
             {2, 2},
         }}
    };

    for (int i = 0; i < testcase.size(); i++)
    {
        Solution s;
        std::cout << ("\033[1;32mTestcase " + std::to_string(i + 1) + "\033[0m") << std::endl;
        auto r = s.vowelStrings(testcase[i].words, testcase[i].queries);
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
