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
        std::vector<int> gift;
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
        long long pickGifts(std::vector<int> &gifts, int k)
        {
            long long remainingGift = 0;
            auto pq                 = std::priority_queue<long long>();

            for (auto gift : gifts)
            {
                pq.push(gift);
            }

            while (k > 0)
            {
                long long tmp = std::floor(std::sqrt(pq.top()));
                pq.pop();
                pq.push(tmp);
                k--;
            }

            while (!pq.empty())
            {
                auto res = pq.top();
                remainingGift += pq.top();
                pq.pop();
            }

            return remainingGift;
        }
};

int main()
{
    std::vector<TestSuit> testcase {
        {{25, 64, 9, 4, 100}, 4},
        {{1, 1, 1, 1},        4},
    };

    for (int i = 0; i < testcase.size(); i++)
    {
        Solution s;
        std::cout << ("\033[1;32mTestcase " + std::to_string(i + 1) + "\033[0m") << std::endl;
        auto r = s.pickGifts(testcase[i].gift, testcase[i].k);
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
