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

// Division
class Solution {
    public:
        bool isValidSudoku(std::vector<std::vector<char>> &board) {
            std::unordered_map<int, std::unordered_set<char>> rows;
            std::unordered_map<int, std::unordered_set<char>> cols;
            std::unordered_map<int, std::unordered_set<char>> squares;

            for (int r = 0; r < 9; r++) {
                for (int c = 0; c < 9; c++) {
                    char cell = board[r][c];
                    if (cell == '.')
                        continue;

                    if (rows[r].count(cell) || cols[c].count(cell) || squares[(r / 3) * 3 + (c / 3)].count(cell)) {
                        return false;
                    }
                    rows[r].insert(cell);
                    cols[c].insert(cell);
                    squares[(r / 3) * 3 + (c / 3)].insert(cell);
                }
            }
            return true;
        }
};

int main() {
    std::vector<std::vector<std::vector<char>>> input = {
        {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
         {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
         {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
         {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
         {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
         {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
         {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
         {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
         {'.', '.', '.', '.', '8', '.', '.', '7', '9'}},
        {{'8', '3', '.', '.', '7', '.', '.', '.', '.'},
         {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
         {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
         {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
         {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
         {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
         {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
         {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
         {'.', '.', '.', '.', '8', '.', '.', '7', '9'}}};

    for (int i = 0; i < input.size(); i++) {
        Solution s;
        std::cout << ("\033[1;32mTestcase " + std::to_string(i + 1) + "\033[0m") << std::endl;
        auto r = s.isValidSudoku(input[i]);
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