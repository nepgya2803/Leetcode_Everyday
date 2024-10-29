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
            std::cout << *it;
        else
            std::cout << *it << ",";

    std::cout << "]" << std::endl;

    return output;
}

class Solution
{
    public:
        std::vector<std::vector<int>> threeSum(std::vector<int> &nums)
        {
            std::vector<std::vector<int>> result;
            std::sort(nums.begin(), nums.end());
            std::set<std::vector<int>> s;
            for (int i = 0; i < nums.size(); i++)
            {
                int j            = i + 1;
                int k            = nums.size() - 1;
                int completement = 0 - nums[i];

                while (j < k)
                    if (nums[j] + nums[k] == completement)
                    {
                        s.insert({nums[i], nums[j], nums[k]});
                        j++;
                        k--;
                    }
                    else if (nums[j] + nums[k] > completement)
                        k--;
                    else
                        j++;
            }

            for (auto triples : s)
                result.push_back(triples);

            return result;
        }
};

int main()
{
    std::vector<std::vector<int>> input = {{-1, 0, 1, 2, -1, -4}, {0, 1, 1}, {0, 0, 0}};
    std::vector<int> target = {9, 6, -1};

    for (int i = 0; i < input.size(); i++)
    {
        Solution s;
        std::cout << ("\033[1;32mTestcase " + std::to_string(i + 1) + "\033[0m") << std::endl;
        auto r = s.threeSum(input[i]);
        std::cout << r << std::endl;
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
