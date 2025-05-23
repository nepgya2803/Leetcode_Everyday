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
        long long maxKelements(std::vector<int> &nums, int k) {
            std::priority_queue<int> pq;
            long long max = 0;
            for (int n : nums) {
                pq.push(n);
            }

            while (k--) {
                int maxQueue = pq.top();
                max += maxQueue;
                pq.pop();
                pq.push(std::ceil(maxQueue / 3.0));
            }

            return max;
        }
};

int main() {
    std::vector<std::vector<int>> input_s1 = {{10, 10, 10, 10, 10}, {1, 10, 3, 3, 3}};
    std::vector<int> target_k = {5, 3};

    for (int i = 0; i < input_s1.size(); i++) {
        Solution s;
        std::cout << ("\033[1;32mTestcase " + std::to_string(i + 1) + "\033[0m") << std::endl;
        auto r = s.maxKelements(input_s1[i], target_k[i]);
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