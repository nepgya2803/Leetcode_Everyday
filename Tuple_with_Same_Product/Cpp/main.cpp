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
        int tupleSameProduct(std::vector<int> &nums)
        {
            int time = 0;
            int size = nums.size();

            std::unordered_map<int, int> productPair;

            for (int firstInd = 0; firstInd < size; firstInd++)
            {
                for (int secondInd = firstInd + 1; secondInd < size; secondInd++)
                {
                    productPair[nums[firstInd] * nums[secondInd]]++;
                }
            }

            for (auto [productValue, productFrequency] : productPair)
            {
                int pairOfEqualProduct = (productFrequency - 1) * productFrequency / 2;
                time += 8 * pairOfEqualProduct;
            }

            return time;
        }
};

int main()
{
    std::vector<TestSuit> testcase {
        {{2, 3, 4, 6}},
        {{1, 2, 4, 5, 10}},
    };

    for (int i = 0; i < testcase.size(); i++)
    {
        Solution s;
        std::cout << ("\033[1;32mTestcase " + std::to_string(i + 1) + "\033[0m") << std::endl;
        auto r = s.tupleSameProduct(testcase[i].nums);
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
