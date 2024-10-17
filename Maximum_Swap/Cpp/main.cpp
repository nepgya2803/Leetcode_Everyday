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
        int maximumSwap(int num) {
            std::string cvtNum = std::to_string(num);
            int current        = 0;

            int n_length       = cvtNum.size();
            int max_num        = num;

            for (int i = 0; i < n_length; i++) {
                for (int j = i + 1; j < n_length; j++) {
                    std::swap(cvtNum[i], cvtNum[j]);
                    max_num = std::max(max_num, std::stoi(cvtNum));
                    std::swap(cvtNum[j], cvtNum[i]);
                }
            }

            return max_num;
        }
};

int main() {
    std::vector<int> input_s1 = {2736, 9973, 1777, 98800435};

    for (int i = 0; i < input_s1.size(); i++) {
        Solution s;
        std::cout << ("\033[1;32mTestcase " + std::to_string(i + 1) + "\033[0m") << std::endl;
        auto r = s.maximumSwap(input_s1[i]);
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