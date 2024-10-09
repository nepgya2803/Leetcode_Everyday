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
	if (input == false) {
		std::cout << "false\n";
	} else {
		std::cout << "true\n";
	}

	std::cout << std::endl;
	return output;
}

template <typename T>
std::ostream &operator<<(std::ostream &output, const int &input) {
	std::cout << input << std::endl;
	return output;
}

class Solution {
	public:
		int minAddToMakeValid(std::string s) {
			if (s.size() == 0) {
				return 0;
			}

			int min = 0;
			std::stack<char> countStk;

			for (char c : s) {
				if (!countStk.empty() && countStk.top() == '(' && c == ')') {
					countStk.pop();
				} else {
					if (!std::isalpha(c))
						countStk.push(c);
				}
			}

			return countStk.size();
		}
};

int main() {
	std::vector<std::string> input_s1 = {"())", "((("};

	for (int i = 0; i < input_s1.size(); i++) {
		Solution s;
		std::cout << ("\033[1;32mTestcase " + std::to_string(i + 1) + "\033[0m") << std::endl;
		auto r = s.minAddToMakeValid(input_s1[i]);
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