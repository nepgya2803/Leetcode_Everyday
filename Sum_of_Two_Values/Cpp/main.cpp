#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string_view>
#include <fstream>

void Solution(int &target, std::vector<int> &arr) {
    std::unordered_map<int, int> collector;

    for (int i = 0; i < arr.size(); i++) {
        int remainder = target - arr[i];

        if (collector.find(remainder) != collector.end()) {
            std::cout << collector[remainder] << " " << i + 1 << std::endl;
            return;
        }

        collector[arr[i]] = i + 1;
    }

    std::cout << "IMPOSSIBLE" << std::endl;
}

int main() {
    int array_size, target = 0;
    std::cin >> array_size >> target;
    std::vector<int> arr(array_size);
    for (int i = 0; i < array_size; i++) {
        std::cin >> arr[i];
    }

    Solution(target, arr);

    return 1;
}
