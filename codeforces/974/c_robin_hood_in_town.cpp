#include <bits/stdc++.h>

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> gold(n);
    for (int i = 0; i < n; i++)
        std::cin >> gold[i];

    if (n <= 2)
    {
        std::cout << -1 << "\n";
        return;        
    }

    std::sort(gold.begin(), gold.end());
    long long kinda_median = (long long) gold[n / 2] * n;
    long long sum = 0;
    for (int i = 0; i < n; i++)
        sum += gold[i];

    if (sum > 2 * kinda_median)
    {
        std::cout << 0 << "\n";
        return;
    }

    long long x = 0;   
    x = (2 * kinda_median - sum) + 1;

    std::cout << x << "\n";
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