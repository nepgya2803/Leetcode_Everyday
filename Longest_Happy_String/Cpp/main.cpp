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
        std::string longestDiverseString(int a, int b, int c) {
            std::priority_queue<std::pair<int, char>> pq;

            if (a > 0) {
                pq.push({a, 'a'});
            }

            if (b > 0) {
                pq.push({b, 'b'});
            }

            if (c > 0) {
                pq.push({c, 'c'});
            }

            std::string ans = "";

            while (!pq.empty()) {
                std::pair<int, char> top = pq.top();
                pq.pop();

                if (ans.size() >= 2 and ans.back() == top.second and ans[ans.size() - 2] == top.second) {
                    if (pq.empty()) {
                        break;
                    }
                    std::pair<int, char> second_top = pq.top();
                    pq.pop();
                    ans += second_top.second;
                    second_top.first--;

                    if (second_top.first > 0)
                        pq.push(second_top);
                    pq.push(top);

                } else {
                    ans += top.second;
                    top.first--;
                    if (top.first > 0)
                        pq.push(top);
                }
            }

            return ans;
        }
};

int main() {
    std::vector<int> input_s1 = {1, 7};
    std::vector<int> input_s2 = {1, 1};
    std::vector<int> input_s3 = {7, 0};

    for (int i = 0; i < input_s1.size(); i++) {
        Solution s;
        std::cout << ("\033[1;32mTestcase " + std::to_string(i + 1) + "\033[0m") << std::endl;
        auto r = s.longestDiverseString(input_s1[i], input_s2[i], input_s3[i]);
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