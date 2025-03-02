#include <bits/stdc++.h>

// Macro
#define fast                          \
    std::ios::sync_with_stdio(false); \
    std::cin.tie(nullptr);

/*
Solution
*/
int Solve(std::vector<int>& foods) {
    int max_customer = 0;

    std::sort(foods.begin(), foods.end(), std::greater<int>());

    for (int i = 0; i < 3; i++) {
        if (foods[i] > 0) {
            foods[i]--;
            max_customer++;
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < i; j++) {
            if (foods[i] != 0 && foods[j] != 0) {
                foods[i]--;
                foods[j]--;
                max_customer++;
            }
        }
    }

    if (foods[0] != 0 && foods[1] != 0 && foods[2] != 0) {
        max_customer++;
    }

    return max_customer;
}

int main() {
    fast;
    int testcase = 0;
    std::cin >> testcase;

    std::vector<int> a(3, 0);

    while (testcase--) {
        std::cin >> a[0] >> a[1] >> a[2];
        int res = Solve(a);
        std::cout << res << std::endl;
    }

    return 0;
}