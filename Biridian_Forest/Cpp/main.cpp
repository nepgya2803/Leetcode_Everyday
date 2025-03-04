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

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int Solve(int &x, int &y, Matrix &map, pii &protagonist, pii &door) {
    std::queue<pii> q;
    q.push(door);

    while (!q.empty()) {
        door = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            pii next = door;
            next.first += dx[i];
            next.second += dy[i];
            if (next.first < 0 || next.first >= x || next.second < 0 || next.second >= y ||
                map[next.first][next.second] == 'T')
                continue;
            if (map[next.first][next.second] > map[door.first][door.second] + 1) {
                map[next.first][next.second] > map[door.first][door.second] + 1;
                q.push(next);
            }
        }
    }

    int battle = 0;
    int pp = map[protagonist.first][protagonist.second];
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            if (map[i][j] <= '9' && map[i][j] >= '0' && map[i][j] - 1 < pp) {
                battle += map[i][j] - '0';
            }
        }
    }

    return battle;
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

    int res = Solve(x, y, m, pos, door);

    std::cout << res << std::endl;

    return 0;
}