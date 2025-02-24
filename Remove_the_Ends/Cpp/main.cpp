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
    std::vector<ll> prefix(size), suffix(size);

    if (nums[0] > 0)
    {
        prefix[0] = nums[0];
    }

    for (int i = 1; i < size; i++)
    {
        prefix[i] = prefix[i - 1];
        if (nums[i] > 0)
        {
            prefix[i] += nums[i];
        }
    }

    if (nums[size - 1] < 0)
    {
        suffix[size - 1] = -nums[size - 1];
    }

    for (int i = size - 2; i >= 0; i--)
    {
        suffix[i] = suffix[i + 1];
        if (nums[i] < 0)
        {
            suffix[i] -= nums[i];
        }
    }

    ll result = 0;
    for (int i = 0; i < size; i++)
    {
        result = std::max(result, prefix[i] + suffix[i]);
    }

    std::cout << result << std::endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int testcase = 0;
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