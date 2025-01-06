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
        std::string boxes;
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
        std::vector<int> minOperations(std::string boxes)
        {
            int size       = boxes.size();
            auto res       = std::vector<int>(size, 0);

            int movetoLeft = 0, ballToLeft = 0;
            int movetoRight = 0, ballToRight = 0;

            for (int i = 0; i < boxes.size(); i++)
            {
                res[i] += movetoLeft;
                ballToLeft += boxes[i] - '0';
                movetoLeft += ballToLeft;

                int j = size - 1 - i;
                res[j] += movetoRight;
                ballToRight += boxes[j] - '0';
                movetoRight += ballToRight;
            }

            return res;
        }
};

int main()
{
    std::vector<TestSuit> testcase {
        {"110"},
        {"001011"},
    };

    for (int i = 0; i < testcase.size(); i++)
    {
        Solution s;
        std::cout << ("\033[1;32mTestcase " + std::to_string(i + 1) + "\033[0m") << std::endl;
        auto r = s.minOperations(testcase[i].boxes);
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
