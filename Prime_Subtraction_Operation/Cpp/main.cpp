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
        bool primeSubOperation(std::vector<int> &nums)
        {
            int n = nums.size();

            for (int i = n - 2; i >= 0; i--)
            {
                if (nums[i] >= nums[i + 1])
                {
                    for (int prime = 2; prime < nums[i]; prime++)
                    {
                        if (IsPrime(prime) && nums[i] - prime < nums[i + 1])
                        {
                            nums[i] -= prime;
                            break;
                        }
                    }
                    if (nums[i] >= nums[i + 1])
                        return false;
                }
            }

            return true;
        }

    private:
        bool IsPrime(int number)
        {
            if (number <= 1)
                return false;
            for (int i = 2; i <= std::sqrt(number); i++)
            {
                if (number % i == 0)
                    return false;
            }
            return true;
        }
};

int main()
{
    std::vector<std::vector<int>> input = {
        {4, 9, 6, 10},
        {6, 8, 11, 12},
        {5, 8, 3},
        {15, 20, 17, 7, 16},
    };

    for (int i = 0; i < input.size(); i++)
    {
        Solution s;
        std::cout << ("\033[1;32mTestcase " + std::to_string(i + 1) + "\033[0m") << std::endl;
        auto r = s.primeSubOperation(input[i]);
        std::cout << std::boolalpha << (r ? true : false) << std::endl;
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
