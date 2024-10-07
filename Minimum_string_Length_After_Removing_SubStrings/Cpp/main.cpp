#include <algorithm>
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
		int minLength(std::string s) {
			int length = s.length();
			std::stack<std::string> st;

			for (int i = 0; i < length; i++) {
				std::string currentchar(1, s[i]);
				if (!st.empty() && (st.top() + currentchar == "AB" || st.top() + currentchar == "CD")) {
					st.pop();
				} else
					st.push(currentchar);
			}

			return st.size();
		}
};

int main() {
	std::vector<std::string> input_s1 = {"ABFCACDB", "ACBBD"};

	for (int i = 0; i < input_s1.size(); i++) {
		Solution s;
		std::cout << ("\033[1;32mTestcase " + std::to_string(i + 1) + "\033[0m") << std::endl;
		auto r = s.minLength(input_s1[i]);
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