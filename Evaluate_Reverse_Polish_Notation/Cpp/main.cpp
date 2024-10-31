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
        int evalRPN(std::vector<std::string> &tokens)
        {
            std::stack<int> st;
            for (auto ch : tokens)
            {
                if (ch == "+")
                {
                    int n1 = st.top();
                    st.pop();
                    int n2 = st.top();
                    st.pop();
                    st.push(n2 + n1);
                }
                else if (ch == "-")
                {
                    int n1 = st.top();
                    st.pop();
                    int n2 = st.top();
                    st.pop();
                    st.push(n2 - n1);
                }
                else if (ch == "*")
                {
                    int n1 = st.top();
                    st.pop();
                    int n2 = st.top();
                    st.pop();
                    st.push(n1 * n2);
                }
                else if (ch == "/")
                {
                    int n1 = st.top();
                    st.pop();
                    int n2 = st.top();
                    st.pop();
                    st.push(n2 / n1);
                }
                else
                {
                    st.push(std::stoi(ch));
                }
            }

            return st.top();
        }
};

int main()
{
    std::vector<std::vector<std::string>> input = {{"2", "1", "+", "3", "*"}, {"4", "13", "5", "/", "+"}, {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"}};

    for (int i = 0; i < input.size(); i++)
    {
        Solution s;
        std::cout << ("\033[1;32mTestcase " + std::to_string(i + 1) + "\033[0m") << std::endl;
        auto r = s.evalRPN(input[i]);
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
