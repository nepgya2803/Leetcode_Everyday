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
        char findKthBit(int n, int k) {
            std::string ans = "0";

            if (n == 1)
                return '0';

            for (int i = 1; i < k && k > ans.size(); i++) {
                ans += "1";
                std::string tmp = ans;

                for (int j = tmp.size() - 2; j >= 0; j--) {
                    char invertedBit = tmp[j] == '1' ? '0' : '1';
                    ans += invertedBit;
                }
            }

            return ans[k - 1];
        }
};

int main() {
    std::vector<int> n = {3, 4};
    std::vector<int> k = {1, 11};

    for (int i = 0; i < n.size(); i++) {
        Solution s;
        std::cout << ("\033[1;32mTestcase " + std::to_string(i + 1) + "\033[0m") << std::endl;
        auto r = s.findKthBit(n[i], k[i]);
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