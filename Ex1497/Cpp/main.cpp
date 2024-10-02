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
		std::cout << "false\n"
	} else {
		std::cout << "true\n";
	}

	std::cout << std::endl;
	return output;
}

class Solution {
	public:
		bool canArrange(std::vector<int> &arr, int k) {
			if (arr.size() / 2 != 0) {
				return false;
			}

            
		}
};

int main() {
	std::vector<std::vector<int>> input_s = {{1, 2, 3, 4, 5, 10, 6, 7, 8, 9}, {1, 2, 3, 4, 5, 6}, {1, 2, 3, 4, 5, 6}};
	std::vector<int> input_k = {5, 7, 10};

	for (int i = 0; i < input_s.size() && i < input_k.size(); i++) {
		Solution s;
		std::cout << ("\033[1;32mTestcase " + std::to_string(i) + "\033[0m") << std::endl;
		std::cout << s.canArrange(input_s[i], input_k[i]) << std::endl;
	}

	return 1;
}