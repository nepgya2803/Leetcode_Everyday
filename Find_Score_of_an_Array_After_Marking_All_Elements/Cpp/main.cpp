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
        long long findScore(std::vector<int> &nums)
        {
            long long ans  = 0;
            auto sortedArr = std::vector<std::pair<int, int>>();

            for (int i = 0; i < nums.size(); i++)
            {
                sortedArr.push_back({nums[i], i});
            }

            std::sort(sortedArr.begin(), sortedArr.end());
            auto markedArray = std::vector<bool>(nums.size(), false);

            for (int i = 0; i < nums.size(); i++)
            {
                int number = sortedArr[i].first;
                int index  = sortedArr[i].second;
                if (!markedArray[index])
                {
                    ans += number;
                    markedArray[index] = true;
                    if (index - 1 >= 0)
                    {
                        markedArray[index - 1] = true;
                    }
                    if (index + 1 < nums.size())
                    {
                        markedArray[index + 1] = true;
                    }
                }
            }

            return ans;
        }
};

int main()
{
    std::vector<TestSuit> testcase {
        {{2, 1, 3, 4, 5, 2}},
        {{2, 3, 5, 1, 3, 2}},
    };

    for (int i = 0; i < testcase.size(); i++)
    {
        Solution s;
        std::cout << ("\033[1;32mTestcase " + std::to_string(i + 1) + "\033[0m") << std::endl;
        auto r = s.findScore(testcase[i].nums);
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
