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
        long long continuousSubarrays(std::vector<int> &nums)
        {
            long long count = 0;
            int size        = nums.size();
            auto frequency  = std::multiset<int>();

            for (int l = 0, r = 0; l < size && r < size; r++)
            {
                frequency.insert(nums[r]);
                while (l < r && *std::prev(frequency.end()) - *frequency.begin() > 2)
                {
                    auto it = frequency.find(nums[l]);
                    frequency.erase(it);
                    l++;
                }
                count += (r - l + 1LL);
            }

            return count;
        }
};

int main()
{
    std::vector<TestSuit> testcase {
        {{5, 4, 2, 4}},
        {{1, 2, 3}},
    };

    for (int i = 0; i < testcase.size(); i++)
    {
        Solution s;
        std::cout << ("\033[1;32mTestcase " + std::to_string(i + 1) + "\033[0m") << std::endl;
        auto r = s.continuousSubarrays(testcase[i].nums);
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
