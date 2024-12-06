#include <bits/stdc++.h>

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    long long sum = 0;
    for (int i = 0; i < n; i++)
        sum += (long long) a[i];

    int goal = sum / (long long) n;

    for (int i = 0; i < n - 2; i++)
    {
        int dist = goal - a[i];
        a[i] = goal;
        a[i + 2] -= dist;
    }

    if (a[n - 2] == goal && a[n - 1] == goal)
        std::cout << "YES\n";
    else
        std::cout << "NO\n";
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