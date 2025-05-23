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
std::ostream &operator<<(std::ostream &output, const long long &input) {
    std::cout << input << std::endl;
    return output;
}

template <typename T>
std::ostream &operator<<(std::ostream &output, const std::vector<T> &input) {
    std::cout << "[";

    for (auto it = input.begin(); it != input.end(); ++it) {
        if (std::next(it) == input.end()) {
            std::cout << *it;
        } else {
            std::cout << *it << ",";
        }
    }

    std::cout << "]" << std::endl;

    return output;
}

class Solution {
    public:
        bool isPalindrome(std::string s) {
            int back = 0;
            int ford = s.size() - 1;

            while (back < ford) {
                while (back < ford && !isAlpha(s[back]))
                    back++;

                while (ford > back && !isAlpha(s[ford]))
                    ford--;

                if (std::tolower(s[ford]) != std::tolower(s[back]))
                    return false;
                else
                    back++, ford--;
            }

            return true;
        }

    private:
        bool isAlpha(char character) {
            char c = std::tolower(character);
            return std::isalpha(c) || std::isdigit(c);
        }
};

int main() {
    std::vector<std::string> input = {"A man, a plan, a canal: Panama", "race a car", " ", "0P"};

    for (int i = 0; i < input.size(); i++) {
        Solution s;
        std::cout << ("\033[1;32mTestcase " + std::to_string(i + 1) + "\033[0m") << std::endl;
        auto r = s.isPalindrome(input[i]);
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
