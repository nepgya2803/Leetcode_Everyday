#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <memory>
#include <queue>
#include <set>
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

// template <typename T>
// std::ostream &operator<<(std::ostream &output, const long long &input) {
// 	std::cout << input << std::endl;
// 	return output;
// }

template <typename Map> bool key_compare(Map const &lhs, Map const &rhs) {
	auto pred = [](decltype(*lhs.begin()) a, decltype(a) b) {
		return a.first == b.first;
	};

	return lhs.size() == rhs.size() && std::equal(lhs.begin(), lhs.end(), rhs.begin(), pred);
}

class Solution {
	public:
		bool checkInclusion(std::string s1, std::string s2) {
			if (s1.size() > s2.size()) {
				return false;
			}

			std::unordered_map<char, int> dict_freq;
			for (char c : s1) {
				dict_freq[c]++;
			}

			int left = 0;
			// int right = s1.size() - 1;

			while (true) {
				if (left >= s2.size()) {
					break;
				}

				std::string subArr = s2.substr(left, s1.size());
				// std::cout << "\033[1;35mSub array is: \033[0m" + subArr << std::endl;
				if (FrequencyCount(dict_freq, subArr)) {
					return true;
				}

				left += 1;
			}

			return false;
		}

	private:
		bool FrequencyCount(std::unordered_map<char, int> dict_freq, std::string subArr) {
			std::unordered_map<char, int> dict_subArr;

			for (char c : subArr) {
				dict_subArr[c]++;
			}

			for (auto &dict : dict_freq) {
				if (dict_subArr.find(dict.first) == dict_subArr.end() || dict_subArr[dict.first] != dict.second)
					return false;
			}

			return true;
		}
};

int main() {
	// 1 2 3 3 4 5
	// clang-format off
	std::vector<std::string> input_s1 = { 
		// "ab", 
		// "ab", 
		// "a", 
		"hello", 
		// "abcdxabcde" 
		};

	std::vector<std::string> input_s2 = { 
		// "eidbaooo", 
		// "eidboaoo", 
		// "b", 
		"ooolleoooleh", 
		// "abcdeabcdx" 
		};
	// clang-format on

	for (int i = 0; i < input_s1.size(); i++) {
		Solution s;
		std::cout << ("\033[1;32mTestcase " + std::to_string(i + 1) + "\033[0m") << std::endl;
		auto r = s.checkInclusion(input_s1[i], input_s2[i]);
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