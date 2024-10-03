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
std::ostream &operator<<(std::ostream &output, const std::vector<T> &input) {
	for (T i : input) {
		std::cout << i << " ";
	}

	std::cout << std::endl;
	return output;
}

template <typename T>
std::ostream &operator<<(std::ostream &output, const int &input) {
	std::cout << "The result is: " + input << std::endl;
	return output;
}

class Solution {
	public:
		int minSubarray(std::vector<int> &nums, int p) {
			long totalSum = 0;
			for (int num : nums) {
				totalSum += num;
			}
			int rem = totalSum % p;
			if (rem == 0)
				return 0;
			std::unordered_map<int, int> prefixMod;
			prefixMod[0] = -1;
			long prefixSum = 0;
			int minLength = nums.size();
			for (int i = 0; i < nums.size(); ++i) {
				prefixSum += nums[i];
				int currentMod = prefixSum % p;
				int targetMod = (currentMod - rem + p) % p;

				if (prefixMod.find(targetMod) != prefixMod.end()) {
					minLength = std::min(minLength, i - prefixMod[targetMod]);
				}

				prefixMod[currentMod] = i;
			}

			return minLength == nums.size() ? -1 : minLength;
		}
};

int main() {
	std::vector<std::vector<int>> input_s = {{3, 1, 4, 2}, {6, 3, 5, 2}, {1, 2, 3}};
	std::vector<int> input_p = {6, 9, 3};

	for (int i = 0; i < input_s.size(); i++) {
		Solution s;
		std::cout << ("\033[1;32mTestcase " + std::to_string(i + 1) + "\033[0m") << std::endl;
		std::cout << s.minSubarray(input_s[i], input_p[i]) << std::endl;
	}

	return 1;
}