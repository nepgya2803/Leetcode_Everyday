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

static const std::vector<std::vector<int>> direction = {
    {1, 3},
    {0, 2, 4},
    {1, 5},
    {0, 4},
    {1, 3, 5},
    {2, 4}
};
static bool visited[543211];
static const int p10[7] = {1, 10, 100, 1000, 10000, 100000, 1000000};
class Solution
{
    public:
        int slidingPuzzle(std::vector<std::vector<int>> const &board)
        {
            memset(visited, false, sizeof(visited));
            std::queue<int> q; // [idx|xyxyxy]
            int idx = 0, value = 0;
            for (int i = 0; i < 6; ++i)
            {
                if (board[i / 3][i % 3] == 0)
                    idx = i;
                value += board[i / 3][i % 3] * p10[i];
            }
            visited[value] = true;
            q.emplace(value + idx * p10[6]);
            int moves = 0;
            while (!q.empty())
            {
                int n = q.size();
                while (n--)
                {
                    int current = q.front();
                    int idx     = current / p10[6];
                    current %= p10[6];
                    q.pop();
                    if (current == 54321)
                        return moves;
                    for (auto nidx : direction[idx])
                    {
                        int v    = (current / p10[nidx]) % 10;
                        int next = current + v * (p10[idx] - p10[nidx]);
                        if (visited[next])
                            continue;
                        visited[next] = true;
                        q.emplace(next + nidx * p10[6]);
                    }
                }
                ++moves;
            }
            return -1;
        }
};

int main()
{
    std::vector<std::vector<std::vector<int>>> testsets = {
        {{1, 2, 3}, {4, 0, 5}},
        {{1, 2, 3}, {5, 4, 0}},
        {{4, 1, 2}, {5, 0, 3}},
    };

    for (int i = 0; i < testsets.size(); i++)
    {
        Solution s;
        std::cout << ("\033[1;32mTestcase " + std::to_string(i + 1) + "\033[0m") << std::endl;
        auto r = s.slidingPuzzle(testsets[i]);
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
