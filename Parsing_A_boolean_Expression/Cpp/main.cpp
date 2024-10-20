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

template <typename T>
std::ostream &operator<<(std::ostream &output, const bool &input) {
    if (input) {
        std::cout << "false\n";
    } else {
        std::cout << "true\n";
    }

    std::cout << std::endl;
    return output;
}

template <typename T>
std::ostream &operator<<(std::ostream &output, const long long &input) {
    std::cout << input << std::endl;
    return output;
}

class Solution {
    public:
        bool parseBoolExpr(std::string expression) {
            std::stack<char> stk;

            for (auto curr : expression) {
                if (curr == ',') {
                    continue;
                } else if (curr == ')') {
                    bool hasTrue  = false;
                    bool hasFalse = false;

                    while (stk.top() != '|' && stk.top() != '!' && stk.top() != '&') {
                        if (stk.top() == 'f')
                            hasFalse = true;

                        if (stk.top() == 't')
                            hasTrue = true;

                        stk.pop();
                    }

                    char op = stk.top();
                    stk.pop();

                    if (op == '!')
                        stk.push(hasTrue ? 'f' : 't');

                    if (op == '&')
                        stk.push(hasFalse ? 'f' : 't');

                    if (op == '|')
                        stk.push(hasTrue ? 't' : 'f');
                } else {
                    stk.push(curr);
                }
            }

            return stk.top() == 't';
        }
};

int main() {
    std::vector<std::string> input = {"&(|(f))", "|(f,f,f,t)", "!(&(f,t))"};
    for (int i = 0; i < input.size(); i++) {
        Solution s;
        std::cout << ("\033[1;32mTestcase " + std::to_string(i + 1) + "\033[0m") << std::endl;
        auto r = s.parseBoolExpr(input[i]);
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