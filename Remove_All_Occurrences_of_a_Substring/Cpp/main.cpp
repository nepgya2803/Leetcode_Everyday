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
#include <unordered_set>
#include <vector>
#include <string_view>

#define LOG_DEBUG(x) (std::cout << x << std::endl)

#define Assert(condition)

struct TestSuit {
public:
    std::string s;
    std::string part;
};

template <typename T>
std::ostream &operator<<(std::ostream &output, const long long &input) {
    std::cout << input << std::endl;
    return output;
}

template <typename T>
std::ostream &operator<<(std::ostream &output, const std::vector<T> &input) {
    std::cout << "[";

    for (auto it = input.begin(); it != input.end(); ++it)
        if (std::next(it) == input.end())
            std::cout << std::boolalpha << *it;
        else
            std::cout << *it << ",";

    std::cout << "]" << std::endl;

    return output;
}

class Solution {
public:
    std::string removeOccurrences(std::string s, std::string part) {
        std::stack<char> originStack;
        int size = s.size();
        int partSize = part.size();

        for (int i = 0; i < size; i++) {
            originStack.push(s[i]);

            if (originStack.size() >= partSize && CheckMatch(originStack, part, partSize)) {
                for (int p = 0; p < partSize; p++) {
                    originStack.pop();
                }
            }
        }

        std::string res;
        while (!originStack.empty()) {
            res = originStack.top() + res;
            originStack.pop();
        }

        return res;
    }

private:
    bool CheckMatch(std::stack<char> &origin, std::string &part, int &partLength) {
        std::stack<char> tmp = origin;
        std::string built;
        for (int i = partLength - 1; i >= 0; i--) {
            built = tmp.top() + built;
            tmp.pop();
        }

        return part == built;
    }
};

int main() {
    std::vector<TestSuit> testcase {
        { "daabcbaabcbc", "abc" },
        { "axxxxyyyyb", "xy" },
        { "daabcbc", "abc " },
    };

    for (int i = 0; i < testcase.size(); i++) {
        Solution s;
        std::cout << ("\033[1;32mTestcase " + std::to_string(i + 1) + "\033[0m") << std::endl;
        auto r = s.removeOccurrences(testcase[i].s, testcase[i].part);
        std::cout << std::boolalpha << r << std::endl;
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
