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

struct TestSuit
{
    public:
        std::string s;
        int k;
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
        std::string repeatLimitedString(std::string s, int k)
        {
            auto frequency = std::map<char, int>();
            for (char c : s)
            {
                frequency[c]++;
            }

            auto pq = std::priority_queue<std::pair<char, int>>();

            for (auto mp : frequency)
            {
                pq.push(std::pair<char, int>(mp.first, mp.second));
            }

            std::basic_string<char> result = std::string();

            while (!pq.empty())
            {
                auto [ch, count] = pq.top();
                pq.pop();
                int used = std::min(count, k);
                result.append(used, ch);
                count -= used;

                if (count > 0)
                {
                    if (pq.empty())
                        break;

                    auto [nextCh, nextCount] = pq.top();
                    pq.pop();
                    result += nextCh;
                    nextCount--;

                    if (nextCount > 0)
                        pq.push({nextCh, nextCount});
                    pq.push({ch, count});
                }
            }

            return result;
        }
};

int main()
{
    std::vector<TestSuit> testcase {
        {"cczazcc", 3},
        {"aababab", 2},
    };

    for (int i = 0; i < testcase.size(); i++)
    {
        Solution s;
        std::cout << ("\033[1;32mTestcase " + std::to_string(i + 1) + "\033[0m") << std::endl;
        auto r = s.repeatLimitedString(testcase[i].s, testcase[i].k);
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
