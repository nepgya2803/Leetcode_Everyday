#include <bits/stdc++.h>

int Solve(int dumpling, int juice, int pancake) {
    int max_customer = 0;

    if (dumpling == 0 && juice == 0 && pancake == 0)
        return max_customer;

    
}

int main() {
    int testcase = 0;
    std::cin >> testcase;

    int dumpling, juice, pancake = 0;

    while (testcase--) {
        std::cin >> dumpling >> juice >> pancake;
        int res = Solve(dumpling, juice, pancake);
        std::cout << res << std::endl;
    }

    return 0;
}