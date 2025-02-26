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
std::map<int, std::vector<int>> adj;
std::map<int, int> visited;

bool Solve(std::vector<int> &nums)
{
    if (nums[0] != 1)
    {
        return false;
    }

    int size = nums.size();
    std::queue<std::set<int>> q;
    std::set<int> s;
    s.insert(1);
    q.push(s);
    int i = 0;

    while (!q.empty() && i < size)
    {
        if (visited.count(nums[i]))
        {
            return false;
        }

        visited[nums[i]] = 1;

        if (q.front().size() == 0)
        {
            q.pop();
        }

        if (q.front().find(nums[i]) == q.front().end())
        {
            return false;
        }

        s.clear();

        for (auto j : adj[nums[i]])
        {
            if (visited.count(j))
            {
                continue;
            }
            s.insert(j);
        }

        if (s.size() > 0)
        {
            std::set<int> tmp = s;
            q.push(tmp);
        }
        s.clear();

        q.front().erase(nums[i]);
        i++;
    }

    return true;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int node, a, b = 0;
    std::cin >> node;

    for (int i = 0; i < node - 1; i++)
    {
        std::cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    std::vector<int> sequence(node);

    int seq = 0;
    for (int i = 0; i < node; i++)
    {
        std::cin >> seq;
        sequence[i] = seq;
    }

    if (Solve(sequence) == true)
    {
        std::cout << "Yes" << std::endl;
    }
    else
    {
        std::cout << "No" << std::endl;
    }

    return 0;
}