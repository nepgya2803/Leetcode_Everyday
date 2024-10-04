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
	if (input = false) {
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
		long long dividePlayers(std::vector<int> &skill) {
			if (skill.size() == 2) {
				return skill[0] * skill[1];
			}

			std::sort(skill.begin(), skill.end(),
					  [](int a, int b) { return a < b; });

			int forwardIdx = 0;
			int backwardIdx = skill.size() - 1;
			int standard = skill[forwardIdx] + skill[backwardIdx];
			long long result = 0;

			while (true) {
				if (forwardIdx > backwardIdx) {
					break;
				}
				if (skill[forwardIdx] + skill[backwardIdx] != standard) {
					return -1;
				} else {
					result += skill[forwardIdx] * skill[backwardIdx];
				}

				forwardIdx++;
				backwardIdx--;
			}

			return result;
		}
};

int main() {
	// 1 2 3 3 4 5
	std::vector<std::vector<int>> input_s = {{3, 2, 5, 1, 3, 4}, {3, 4}, {1, 1, 2, 3}};

	for (int i = 0; i < input_s.size(); i++) {
		Solution s;
		std::cout << ("\033[1;32mTestcase " + std::to_string(i) + "\033[0m") << std::endl;
		std::cout << s.dividePlayers(input_s[i]) << std::endl;
	}

	return 1;
}