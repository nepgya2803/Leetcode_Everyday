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

class MinStack
{
    public:
        std::stack<int> minStack;
        std::stack<int> stk;

        MinStack() {}

        void push(int val)
        {
            stk.push(val);
            if (minStack.empty() || minStack.top() >= val)
                minStack.push(val);
        }

        void pop()
        {
            if (stk.empty())
                return;

            int top = stk.top();
            stk.pop();

            if (!minStack.empty() && top == minStack.top())
            {
                minStack.pop();
            }
        }

        int top()
        {
            return stk.top();
        }

        int getMin()
        {
            return minStack.top();
        }
};

int main()
{
    MinStack *minStack = new MinStack();
    minStack->push(-2);
    minStack->push(0);
    minStack->push(-3);
    std::cout << minStack->getMin() << std::endl; // return -3
    minStack->pop();
    std::cout << minStack->top() << std::endl;    // return 0
    std::cout << minStack->getMin() << std::endl; // return -2

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
