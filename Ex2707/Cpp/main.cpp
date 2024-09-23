#include <cmath>
#include <cstring>
#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <unordered_set>
#include <vector>

class Solution {
	public:
		int n;
		std::vector<int> dp;
		std::unordered_set<std::string> st;
		int solve(int idx, std::string &s) {
			if (idx == n)
				return 0;

			if (dp[idx] != -1)
				return dp[idx];

			std::string cur;
			int minimumExtra = n;
			for (int i = idx; i < n; i++) {
				cur += s[i];

				int nextExtra = solve(i + 1, s);
				int curExtra = (st.count(cur)) ? 0 : cur.size();

				minimumExtra = std::min(minimumExtra, curExtra + nextExtra);
			}
			return dp[idx] = minimumExtra;
		}
		int minExtraChar(std::string s, std::vector<std::string> &dictionary) {
			n = s.size();
			dp.resize(55, -1);
			for (auto &dict : dictionary)
				st.insert(dict);
			return solve(0, s);
		}
};
int main() {
	std::vector<std::string> input_s = {"leetscode", "sayhelloworld"};
	std::vector<std::vector<std::string>> input_dict = {{"leet", "code", "leetcode"}, {"hello", "world"}};
	for (int i = 0; i < input_s.size() && i < input_dict.size(); i++) {
		Solution sol;
		std::cout << sol.minExtraChar(input_s[i], input_dict[i]) << std::endl;
	}

	return 1;
}