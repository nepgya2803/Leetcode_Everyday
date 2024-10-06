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
#include <unordered_map>
#include <vector>

template <typename T>
std::ostream &operator<<(std::ostream &output, const bool &input) {
	if (input == 0) {
		std::cout << "false\n";
	} else {
		std::cout << "true\n";
	}

	std::cout << std::endl;
	return output;
}

// template <typename T>
// std::ostream &operator<<(std::ostream &output, const long long &input) {
// 	std::cout << input << std::endl;
// 	return output;
// }

class Solution {
	public:
		bool areSentencesSimilar(std::string sentence1, std::string sentence2) {
			std::istringstream iss1(sentence1);
			std::istringstream iss2(sentence2);

			std::deque<std::string> dq1 {std::istream_iterator<std::string>(iss1), std::istream_iterator<std::string>()};
			std::deque<std::string> dq2 {std::istream_iterator<std::string>(iss2), std::istream_iterator<std::string>()};

			while (!dq1.empty() && !dq2.empty() && dq1.front() == dq2.front()) {
				dq1.pop_front();
				dq2.pop_front();
			}

			while (!dq1.empty() && !dq2.empty() && dq1.back() == dq2.back()) {
				dq1.pop_back();
				dq2.pop_back();
			}

			return dq1.empty() || dq2.empty();
		}
};

int main() {
	std::vector<std::string> input_s1 = {"My name is Haley", "of", "Eating right now"};

	std::vector<std::string> input_s2 = {"My Haley", "A lot of words", "Eating"};

	for (int i = 0; i < input_s1.size(); i++) {
		Solution s;
		std::cout << ("\033[1;32mTestcase " + std::to_string(i + 1) + "\033[0m") << std::endl;
		auto r = s.areSentencesSimilar(input_s1[i], input_s2[i]);
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