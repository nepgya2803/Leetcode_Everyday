#include <bits/stdc++.h>

// ----------------- MACRO ------------------//
#define fast                          \
    std::ios::sync_with_stdio(false); \
    std::cin.tie(nullptr);
#define pii std::pair<int, int>
#define mp std::make_pair
#define LOG_DEBUG(x) (std::cout << x << std::endl)
// ----------------- MACRO ------------------//

// ----------------- TYPEDEF ------------------//
typedef std::vector<int> vi;
typedef std::vector<std::string> vs;
typedef std::vector<std::vector<char>> vvc;
typedef std::vector<std::vector<int>> vvi;
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
vs map(1005);
vvi distance(1005, vi(1005));

int Solve(int &x, int &y, pii &now, pii &goal) {
    std::queue<pii> q;
    q.push(now);

    while (!q.empty()) {
        now = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            pii next = now;
            next.first += dx[i];
            next.second += dy[i];
            if (next.first < 0 || next.first >= x)
                continue;
            if (next.second < 0 || next.second >= y)
                continue;
            if (map[next.first][next.second] == 'T')
                continue;
            if (distance[next.first][next.second] > distance[now.first][now.second] + 1) {
                distance[next.first][next.second] = distance[now.first][now.second] + 1;
                q.push(next);
            }
        }
    }

    int battle = 0;
    int pp = distance[goal.first][goal.second];
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            if (map[i][j] <= '9' && map[i][j] >= '0' && distance[i][j] - 1 < pp) {
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
    pii now, goal;
    std::cout << x << y;
    for (int i = 0; i < x; i++) {
        std::cin >> map[i];

        for (int j = 0; j < y; j++) {
            if (map[i][j] == 'E') {
                now = mp(i, j);
                distance[i][j] = 0;
            }

            if (map[i][j] == 'S')
                goal = mp(i, j);
        }
    }

    int res = Solve(x, y, now, goal);

    std::cout << res << std::endl;

    return 0;
}