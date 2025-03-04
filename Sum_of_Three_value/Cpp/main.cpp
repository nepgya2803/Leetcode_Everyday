#include <bits/stdc++.h>
#define ll long long
#define lli long long int
#define DEBUG(x) (std::cout << x << std::endl)
#define Assert(condition)

template <typename T>
std::ostream &operator<<(std::ostream &output, const bool &input) {
    if (input) {
        std::cout << "false\n";
    }
    else {
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

template <typename T>
std::ostream &operator<<(std::ostream &output, const std::vector<T> &input) {
    std::cout << "[";

    for (auto it = input.begin(); it != input.end(); ++it) {
        if (std::next(it) == input.end()) {
            std::cout << *it;
        }
        else {
            std::cout << *it << ",";
        }
    }

    std::cout << "]" << std::endl;

    return output;
}

/*
Solution
*/
void Solve(const lli &size, std::vector<lli> &nums, const lli &target) {
    std::vector<std::vector<lli>> copy(size, std::vector<lli>(2, 0));

    for (int i = 0; i < size; i++) {
        copy[i][0] = nums[i];
        copy[i][1] = i + 1;
    }

    std::sort(copy.begin(), copy.end());

    for (lli ptr1 = 0; ptr1 < size - 2; ptr1++) {
        lli remainder = target - copy[ptr1][0];
        lli ptr2 = ptr1 + 1;
        lli ptr3 = size - 1;

        while (ptr2 < ptr3) {
            if (copy[ptr2][0] + copy[ptr3][0] == remainder) {
                std::cout << copy[ptr1][1] << " " << copy[ptr2][1] << " " << copy[ptr3][1] << std::endl;
                return;
            }

            if (copy[ptr2][0] + copy[ptr3][0] > remainder) {
                ptr3--;
            }

            if (copy[ptr2][0] + copy[ptr3][0] < remainder) {
                ptr2++;
            }
        }
    }

    std::cout << "IMPOSSIBLE" << std::endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    lli size, target = 0;
    std::cin >> size >> target;
    std::vector<lli> arr(size);

    for (int i = 0; i < size; i++) {
        std::cin >> arr[i];
    }

    Solve(size, arr, target);

    return 0;
}