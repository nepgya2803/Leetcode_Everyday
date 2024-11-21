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
        int takeCharacters(std::string s, int k)
        {
            int ans    = INT32_MAX;
            auto store = std::vector<int>(3, 0);

            for (auto c : s)
            {
                store[c - 'a']++;
            }

            for (auto p : store)
            {
                if (p < k)
                {
                    return -1;
                }
            }

            int l = 0;

            for (int r = 0; r < s.length(); r++)
            {
                store[s[r] - 'a']--;

                while (*std::min_element(store.begin(), store.end()) < k)
                {
                    store[s[l] - 'a']++;
                    l++;
                }
                ans = std::min(ans, static_cast<int>(s.length()) - (r - l + 1));
            }
            return ans;
        }
};

int main()
{
    std::vector<std::string> input = {
        "aabaaaacaabc",
        "a",
    };

    std::vector<int> k = {
        2,
        1,
    };

    for (int i = 0; i < input.size(); i++)
    {
        Solution s;
        std::cout << ("\033[1;32mTestcase " + std::to_string(i + 1) + "\033[0m") << std::endl;
        auto r = s.takeCharacters(input[i], k[i]);
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
