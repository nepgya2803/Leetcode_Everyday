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
        std::vector<std::vector<char>> rotateTheBox(std::vector<std::vector<char>> &box)
        {
            int row = box.size();
            int col = box[0].size();
            auto rotatedMatrix = std::vector<std::vector<char>>(col, std::vector<char>(row, '.'));

            for (int r = 0; r < row; r++)
            {
                int cur_empty = col - 1;
                for (int c = col - 1; c >= 0; c--)
                {
                    if (box[r][c] == '*')
                    {
                        rotatedMatrix[c][row - 1 - r] = '*';
                        cur_empty                     = c - 1;
                    }
                    if (box[r][c] == '#')
                    {
                        rotatedMatrix[cur_empty][row - 1 - r] = '#';
                        cur_empty--;
                    }
                }
            }

            return rotatedMatrix;
        }
};

int main()
{
    std::vector<std::vector<std::vector<char>>> testsets = {
        {
         {'#', '.', '#'},
         },
        //
        {
         {'#', '.', '*', '.'},
         {'#', '#', '*', '.'},
         },
        //
        {
         {'#', '#', '*', '.', '*', '.'},
         {'#', '#', '#', '*', '.', '.'},
         {'#', '#', '#', '.', '#', '.'},
         },
    };

    for (int i = 0; i < testsets.size(); i++)
    {
        Solution s;
        std::cout << ("\033[1;32mTestcase " + std::to_string(i + 1) + "\033[0m") << std::endl;
        auto r = s.rotateTheBox(testsets[i]);
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
