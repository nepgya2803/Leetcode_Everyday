#include <bits/stdc++.h>

void Solve(int &x, int &y)
{
    bool result = false;

    if (y == x + 1)
    {
        result = true;
    }
    else
    {
        if (x > y && (x - y + 1) % 9 == 0)
        {
            result = true;
        }
    }

    std::cout << (result ? "Yes" : "No") << std::endl;
    return;
}

int main()
{
    int testcase = 0;
    std::cin >> testcase;

    for (int i = 0; i < testcase; i++)
    {
        int x, y = 0;
        std::cin >> x >> y;
        Solve(x, y);
    }

    return 0;
}