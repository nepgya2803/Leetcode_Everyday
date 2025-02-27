#include <bits/stdc++.h>
#define ll long long
#define LOG_DEBUG(x) (std::cout << x << std::endl)
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
void Solve(const int &size, std::vector<int> &nums, const int &target) {
    int count = 0;
    int currentSum = 0;

    for (int left = 0, right = 0; right < size; right++) {
        currentSum += nums[right];

        while (currentSum > target) {
            currentSum -= nums[left++];
        }

        if (currentSum == target)
            count++;
    }

    std::cout << count << std::endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int size, target = 0;
    std::cin >> size >> target;
    std::vector<int> arr(size);

    for (int i = 0; i < size; i++) {
        std::cin >> arr[i];
    }

    Solve(size, arr, target);

    return 0;
}