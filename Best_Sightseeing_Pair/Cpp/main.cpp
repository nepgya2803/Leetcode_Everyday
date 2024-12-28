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
        std::vector<int> nums;
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
        int maxScoreSightseeingPair(std::vector<int> &values)
        {
            int max_score     = 0;
            int size          = values.size();
            int left_maxscore = values[0];
            for (int i = 1; i < size; i++)
            {
                int right_score = values[i] - i;

                max_score = std::max(max_score, right_score + left_maxscore);

                int left_score = values[i] + i;

                left_maxscore  = std::max(left_maxscore, values[i] + i);
            }

            return max_score;
        }
};

int main()
{
    std::vector<TestSuit> testcase {
        {{8, 1, 5, 2, 6}},
        {{1, 2}},
    };

    for (int i = 0; i < testcase.size(); i++)
    {
        Solution s;
        std::cout << ("\033[1;32mTestcase " + std::to_string(i + 1) + "\033[0m") << std::endl;
        auto r = s.maxScoreSightseeingPair(testcase[i].nums);
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
