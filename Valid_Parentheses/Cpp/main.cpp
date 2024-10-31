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
        bool isValid(std::string s)
        {
            std::stack<char> st;
            if (s.size() == 0)
                return false;

            for (char ch : s)
            {
                if (st.size() == 0)
                {
                    st.push(ch);
                    continue;
                }

                if ((st.top() == '[' && ch == ']') || (st.top() == '(' && ch == ')') || (st.top() == '{' && ch == '}'))
                {
                    st.pop();
                }
                else
                {
                    st.push(ch);
                }
            }
            return st.size() == 0;
        }
};

int main()
{
    std::vector<std::string> input = {"()", "()[]{}", "(]", "([])"};

    for (int i = 0; i < input.size(); i++)
    {
        Solution s;
        std::cout << ("\033[1;32mTestcase " + std::to_string(i + 1) + "\033[0m") << std::endl;
        auto r = s.isValid(input[i]);
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
