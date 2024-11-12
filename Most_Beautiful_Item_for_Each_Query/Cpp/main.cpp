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
        std::vector<int> maximumBeauty(std::vector<std::vector<int>> &items, std::vector<int> &queries)
        {
            std::vector<int> maxArr(queries.size(), 0);

            std::sort(items.begin(), items.end(), [](std::vector<int> a, std::vector<int> b) {
                return a[0] < b[0];
            });

            for (auto i : items)
                std::cout << i;
            std::cout << std::endl;

            return maxArr;
        }

    private:
        int BinarySearch(std::vector<int> items)
        {
            
        }
};

int main()
{
    std::vector<std::vector<std::vector<int>>> input = {
        {{1, 2}, {3, 2}, {2, 4}, {5, 6}, {3, 5}},
        {{1, 2}, {1, 2}, {1, 3}, {1, 4}},
        {{10, 1000}},
    };

    std::vector<std::vector<int>> queries = {
        {1, 2, 3, 4, 5, 6},
        {1},
        {5},
    };

    for (int i = 0; i < input.size(); i++)
    {
        Solution s;
        std::cout << ("\033[1;32mTestcase " + std::to_string(i + 1) + "\033[0m") << std::endl;
        auto r = s.maximumBeauty(input[i], queries[i]);
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
