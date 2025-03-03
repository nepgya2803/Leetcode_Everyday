#include <bits/stdc++.h>

// ----------------- MACRO ------------------//
#define fast                          \
    std::ios::sync_with_stdio(false); \
    std::cin.tie(nullptr);
#define pii std::pair<int, int>
#define mp std::make_pair
// ----------------- MACRO ------------------//

// ----------------- TYPEDEF ------------------//
typedef std::vector<std::vector<char>> Matrix;
typedef std::vector<char> OneLine;
// ----------------- CLOSE ------------------//

// ----------------- TEMPLATE ------------------//
template <typename T>
std::ostream &operator<<(std::ostream &output, const long long &input) {
    std::cout << input << std::endl;
    return output;
}

template <typename T>
std::ostream &operator<<(std::ostream &output, const std::vector<T> &input) {
    std::cout << "[";

    for (auto it = input.begin(); it != input.end(); ++it)
        if (std::next(it) == input.end())
            std::cout << std::boolalpha << *it;
        else
            std::cout << *it << ",";

    std::cout << "]" << std::endl;

    return output;
}
// ----------------- TEMPLATE ------------------//

/*
Solution
*/

int Solve(int &x, int &y, Matrix &map, pii &protagonist, pii &door) {
    
}

int main() {
    fast;
    int x, y = 0;
    std::cin >> x >> y;
    Matrix m(x, OneLine(y));
    pii pos, door;
    std::string row = "";

    for (int i = 0; i < x; i++) {
        std::cin >> row;
        for (int s = 0; s < y; s++) {
            m[i][s] = row[s];
            if (row[s] == 'E')
                door = mp(i, s);
            if (row[s] == 'S')
                pos = mp(i, s);
        }
    }

    int res = Solve(x, y, m);

    return 0;
}