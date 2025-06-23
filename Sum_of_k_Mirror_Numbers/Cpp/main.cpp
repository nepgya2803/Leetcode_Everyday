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
    int k;
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
    long long kMirror(int k, int n) {
        long long result = 0;

        for (long long len = 1; n > 0; len *= 10) {
            for (long long num = len; n > 0 && num < len * 10; num++) {
                long long palindrom_number = generatePalindrome(num, true);

                if (isPalinDrom(palindrom_number, k)) {
                    n--;
                    result += palindrom_number;
                }
            }

            for (long long num = len; n > 0 && num < len * 10; num++) {
                long long palindrom_number = generatePalindrome(num, false);

                if (isPalinDrom(palindrom_number, k)) {
                    n--;
                    result += palindrom_number;
                }
            }
        }

        return result;
    }

private:
    long long generatePalindrome(long long origin, bool isOdd) {
        long long tmp = origin;

        if (isOdd) {
            tmp /= 10;
        }

        while (tmp > 0) {
            origin = origin * 10 + tmp % 10;
            tmp /= 10;
        }

        return origin;
    }

    bool isPalinDrom(long long number, int base) {
        std::vector<int> digits;

        while (number > 0) {
            digits.push_back(number % base);
            number /= base;
        }

        int left = 0, right = digits.size() - 1;

        while (left < right) {
            if (digits[left++] != digits[right--]) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    std::vector<TestSuit> testcase {
        { 2, 5 },
        { 3, 7 },
        { 7, 17 },
    };

    for (int i = 0; i < testcase.size(); i++) {
        Solution s;
        std::cout << ("\033[1;32mTestcase " + std::to_string(i + 1) + "\033[0m") << std::endl;
        auto r = s.kMirror(testcase[i].k, testcase[i].n);
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
