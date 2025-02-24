#include <bits/stdc++.h>
#define ll long long

template <typename T>
std::ostream &operator<<(std::ostream &output, const bool &input)
{
    if (input)
    {
        std::cout << "false\n";
    }
    else
    {
        std::cout << "true\n";
    }

    std::cout << std::endl;
    return output;
}

template <typename T>
std::ostream &operator<<(std::ostream &output, const long long &input)
{
    std::cout << input << std::endl;
    return output;
}

template <typename T>
std::ostream &operator<<(std::ostream &output, const std::vector<T> &input)
{
    std::cout << "[";

    for (auto it = input.begin(); it != input.end(); ++it)
    {
        if (std::next(it) == input.end())
        {
            std::cout << *it;
        }
        else
        {
            std::cout << *it << ",";
        }
    }

    std::cout << "]" << std::endl;

    return output;
}

/*
Solution
*/
void Solve(int &size, std::vector<ll> &nums)
{
    
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int node = 0;
    std::cin >> testcase;

    while (testcase--)
    {
        int n = 0;
        std::cin >> n;
        std::vector<ll> nums(n);

        for (int i = 0; i < n; i++)
        {
            std::cin >> nums[i];
        }

        Solve(n, nums);
    }

    return 0;
}