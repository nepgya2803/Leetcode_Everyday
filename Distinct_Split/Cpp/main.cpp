#include <bits/stdc++.h>

// Macro
#define fast                          \
    std::ios::sync_with_stdio(false); \
    std::cin.tie(nullptr);

/*
Solution
*/
int Solve(int length, std::string s) {
    int max = 0;

    int pre[length], suff[length];
    std::unordered_set<char> hSet;

    for (int i = 0; i < length; i++) {
        hSet.insert(s[i]);
        pre[i] = hSet.size();
    }

    hSet.clear();

    for (int i = length - 1; i >= 0; i--) {
        hSet.insert(s[i]);
        suff[i] = hSet.size();
    }

    for (int i = 0; i < length - 1; i++) {
        max = std::max(max, suff[i + 1] + pre[i]);
    }

    return max;
}

int main() {
    fast;
    int testcase = 0;
    std::cin >> testcase;

    int length = 0;
    std::string s = "";

    while (testcase--) {
        std::cin >> length >> s;
        int res = Solve(length, s);
        std::cout << res << std::endl;
    }

    return 0;
}