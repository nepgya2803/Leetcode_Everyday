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
        int findLengthOfShortestSubarray(std::vector<int> &arr)
        {
            int n     = arr.size();
            int left  = 0;
            int right = n - 1;

            for (; right > 0 && arr[right] >= arr[right - 1];)
            {
                right--;
            }
            int ans = right;

            if (right == 0)
                return 0;

            while (left < right && (left == 0 || arr[left - 1] <= arr[left]))
            {
                while (right < arr.size() && arr[left] > arr[right])
                {
                    right++;
                }
                ans = std::min(ans, right - left - 1);
                left++;
            }

            return ans;
        }
};

int main()
{
    std::vector<std::vector<int>> input = {
        {1, 2, 3, 10, 4, 2, 3, 5},
        {5, 4, 3, 2, 1},
        {1, 2, 3},
    };

    for (int i = 0; i < input.size(); i++)
    {
        Solution s;
        std::cout << ("\033[1;32mTestcase " + std::to_string(i + 1) + "\033[0m") << std::endl;
        auto r = s.findLengthOfShortestSubarray(input[i]);
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
