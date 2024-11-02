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
        int search(std::vector<int> &nums, int target)
        {
            int left = 0, right = nums.size() - 1;
            int mid = (left + right) / 2;

            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
            {
                right = mid - 1;
                while (left <= right)
                {
                    if (nums[left] == target)
                        return left;
                    left++;
                }
            }
            else
            {
                left = mid + 1;
                while (left <= right)
                {
                    if (nums[left] == target)
                        return left;
                    left++;
                }
            }

            return -1;
        }
};

int main()
{
    std::vector<std::vector<int>> input = {{-1, 0, 3, 5, 9, 12}, {-1, 0, 3, 5, 9, 12}};
    std::vector<int> target {9, 2};
    for (int i = 0; i < input.size(); i++)
    {
        Solution s;
        std::cout << ("\033[1;32mTestcase " + std::to_string(i + 1) + "\033[0m") << std::endl;
        auto r = s.search(input[i], target[i]);
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
