#include <bits/stdc++.h>

long long dfs(long long size, std::map<long long, std::vector<int>> &values, std::set<long long> &closed)
{
    long long result = size;
    for (int i = 0; i < values[size].size(); i++)
        if (!closed.contains(size))
            result = std::max(dfs(size + (long long) values[size][i], values, closed), result);

    closed.insert(size);
    return result;
}

void solve()
{
    int n;
    std::cin >> n;

    std::vector<long long> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];
    
    std::map<long long, std::vector<int>> values;
    for (int i = 1; i < n; i++)
    {
        long long value = a[i] + (long long) i;
        values[value].push_back(i);
    }

    std::set<long long> closed;
    long long result = dfs(n, values, closed);
    std::cout << result << "\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    int t;
    std::cin >> t;
    while (t--)
        solve();

    return 0;
}