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
        std::vector<std::string> words1;
        std::vector<std::string> words2;
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
        std::vector<std::string> wordSubsets(std::vector<std::string> &words1, std::vector<std::string> &words2)
        {
            std::vector<std::string> res;
            std::unordered_map<char, int> max_frequency;

            for (std::string &word : words2)
            {
                for (char &c : word)
                {
                    max_frequency[c]++;
                }
            }

            for (std::string &word : words1)
            {
                int isSubset = false;

                for (char &c : word)
                {
                    if (max_frequency.find(c) != max_frequency.end())
                    {
                        isSubset = true;
                    }
                    else
                    {
                        isSubset = false;
                        break;
                    }
                }

                if (isSubset)
                {
                    res.push_back(word);
                }
            }

            return res;
        }
};

int main()
{
    std::vector<TestSuit> testcase {
        {{"amazon", "apple", "facebook", "google", "leetcode"}, {"e", "o"}},
        {{"amazon", "apple", "facebook", "google", "leetcode"}, {"l", "e"}},
    };

    for (int i = 0; i < testcase.size(); i++)
    {
        Solution s;
        std::cout << ("\033[1;32mTestcase " + std::to_string(i + 1) + "\033[0m") << std::endl;
        auto r = s.wordSubsets(testcase[i].words1, testcase[i].words2);
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
