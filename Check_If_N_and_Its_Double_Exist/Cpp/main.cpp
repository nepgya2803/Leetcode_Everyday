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
        bool checkIfExist(std::vector<int> &arr)
        {
            auto storage = std::set<int>();
            int n        = arr.size();

            for (const auto &num : arr)
            {
                if (storage.count(2 * num) || (num % 2 == 0 && storage.count(num / 2)))
                {
                    return true;
                }
                storage.insert(num);
            }

            return false;
        }
};

int main()
{
    std::vector<std::vector<int>> testsets = {
        {10, 2, 5, 3},
        {3, 1, 7, 11},
        {-10, 12, -20, -8, 15},
    };

    for (int i = 0; i < testsets.size(); i++)
    {
        Solution s;
        std::cout << ("\033[1;32mTestcase " + std::to_string(i + 1) + "\033[0m") << std::endl;
        auto r = s.checkIfExist(testsets[i]);
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
