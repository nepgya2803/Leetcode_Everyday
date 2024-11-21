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

struct TestSet
{
        int m;
        int n;
        std::vector<std::vector<int>> guards;
        std::vector<std::vector<int>> wall;
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
            std::cout << *it;
        else
            std::cout << *it << ",";

    std::cout << "]" << std::endl;

    return output;
}

class Solution
{
    public:
        const int UNGUARDED = 0;
        const int GUARDED   = 1;
        const int GUARD     = 2;
        const int WALL      = 3;

        void markguarded(int row, int col, std::vector<std::vector<int>> &grid)
        {
            // Traverse upwards
            for (int r = row - 1; r >= 0; r--)
            {
                if (grid[r][col] == WALL || grid[r][col] == GUARD)
                    break;
                grid[r][col] = GUARDED;
            }
            // Traverse downwards
            for (int r = row + 1; r < grid.size(); r++)
            {
                if (grid[r][col] == WALL || grid[r][col] == GUARD)
                    break;
                grid[r][col] = GUARDED;
            }
            // Traverse leftwards
            for (int c = col - 1; c >= 0; c--)
            {
                if (grid[row][c] == WALL || grid[row][c] == GUARD)
                    break;
                grid[row][c] = GUARDED;
            }
            // Traverse rightwards
            for (int c = col + 1; c < grid[row].size(); c++)
            {
                if (grid[row][c] == WALL || grid[row][c] == GUARD)
                    break;
                grid[row][c] = GUARDED;
            }
        }

        int countUnguarded(int m, int n, std::vector<std::vector<int>> &guards, std::vector<std::vector<int>> &walls)
        {
            std::vector<std::vector<int>> grid(m, std::vector<int>(n, UNGUARDED));

            // Mark guards' positions
            for (const auto &guard : guards)
            {
                grid[guard[0]][guard[1]] = GUARD;
            }

            // Mark walls' positions
            for (const auto &wall : walls)
            {
                grid[wall[0]][wall[1]] = WALL;
            }

            // Mark cells as guarded by traversing from each guard
            for (const auto &guard : guards)
            {
                markguarded(guard[0], guard[1], grid);
            }

            // Count unguarded cells
            int count = 0;
            for (const auto &row : grid)
            {
                for (const auto &cell : row)
                {
                    if (cell == UNGUARDED)
                        count++;
                }
            }
            return count;
        }
};

int main()
{
    std::vector<TestSet> testsets = {
        {
         4, 6,
         {{0, 0}, {1, 1}, {2, 3}},
         {{0, 1}, {2, 2}, {1, 4}},
         },
        {
         3, 3,
         {{1, 1}},
         {{0, 1}, {1, 0}, {2, 1}, {1, 2}},
         },
    };

    for (int i = 0; i < testsets.size(); i++)
    {
        Solution s;
        std::cout << ("\033[1;32mTestcase " + std::to_string(i + 1) + "\033[0m") << std::endl;
        auto r = s.countUnguarded(testsets[i].m, testsets[i].n, testsets[i].guards,
                                  testsets[i].wall);
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
