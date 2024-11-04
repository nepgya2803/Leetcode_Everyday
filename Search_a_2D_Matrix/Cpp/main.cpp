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
        bool searchMatrix(std::vector<std::vector<int>> &matrix, int target)
        {
            int rows = matrix.size(), cols = matrix[0].size();

            int row = 0, col = cols - 1;

            while (row < rows && col > -1)
            {
                if (matrix[row][col] == target)
                    return true;

                if (matrix[row][col] < target)
                    row++;
                else
                    col--;
            }

            return false;
        }
};

int main()
{
    std::vector<std::vector<std::vector<int>>> input = {
        {
         {1, 3, 5, 7},
         {10, 11, 16, 20},
         {23, 30, 34, 60},
         },
        {
         {1, 3, 5, 7},
         {10, 11, 16, 20},
         {23, 30, 34, 60},
         },
    };

    std::vector<int> target {3, 13};

    for (int i = 0; i < input.size(); i++)
    {
        Solution s;
        std::cout << ("\033[1;32mTestcase " + std::to_string(i + 1) + "\033[0m") << std::endl;
        auto r = s.searchMatrix(input[i], target[i]);
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
