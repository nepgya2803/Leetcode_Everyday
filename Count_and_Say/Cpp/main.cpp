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
#include <list>

#define LOG_DEBUG(x) (std::cout << x << std::endl)

#define Assert(condition)

struct TestSuit {
public:
    int n;
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
    std::string countAndSay(int n) {
        std::string res = "1";
        for (int i = 1; i < n; i++) {
            res = desribe(res);
        }

        return res;
    }

private:
    std::string desribe(std::string origin) {
        std::string temp = "";
        int count = 1;

        for (int i = 1; i < origin.size(); i++) {
            if (origin[i] == origin[i - 1]) {
                count++;
            }
            else {
                temp += std::to_string(count) + origin[i - 1];
                count = 1;
            }
        }

        temp += std::to_string(count) + origin.back();
        return temp;
    }
};

int main() {
    std::vector<TestSuit> testcase {
        { 1 },
        { 4 },
    };

    for (int i = 0; i < testcase.size(); i++) {
        Solution s;
        std::cout << ("\033[1;32mTestcase " + std::to_string(i + 1) + "\033[0m") << std::endl;
        auto r = s.countAndSay(testcase[i].n);
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
