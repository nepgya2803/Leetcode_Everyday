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

class Solution {
	public:
		std::vector<int> arrayRankTransform(std::vector<int> &arr) {
			// Create a copy array
			std::vector<int> arr_cpy(arr.size());

			// Copy element
			std::copy(arr.begin(), arr.end(), arr_cpy.begin());

			// Sort the copy
			std::sort(arr_cpy.begin(), arr_cpy.end(),
					  [](int a, int b) { return a < b; });

			// Create dictionary
			std::unordered_map<int, int> map_dict;
			int rank = 1;

			for (int i = 0; i < arr_cpy.size(); i++) {
				if (i > 0 && arr_cpy[i] == arr_cpy[i - 1]) {
					rank--;
				}
				map_dict[arr_cpy[i]] = rank;
				rank++;
			}

			std::cout << arr_cpy << std::endl;

			// Create result vector
			std::vector<int> result(arr.size());

			for (int i = 0; i < arr.size(); i++) {
				result[i] = map_dict[arr[i]];
			}

			return result;
		}
};

int main() {
	std::vector<std::vector<int>> input_s = {// {40, 10, 20, 30},
											 // {100, 100, 100},
											 {37, 12, 28, 9, 100, 56, 80, 5, 12}};

	for (int i = 0; i < input_s.size(); i++) {
		Solution s;
		std::cout << ("\033[1;32mTestcase " + std::to_string(i + 1) + "\033[0m") << std::endl;
		std::cout << s.arrayRankTransform(input_s[i]) << std::endl;
	}

	return 1;
}