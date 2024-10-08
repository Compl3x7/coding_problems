#include <bits/stdc++.h>

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> ratings(n);
    for (int i = 0; i < n; i++)
        std::cin >> ratings[i];

    long long max_rating = ratings[n - 1];
    long long sub = ratings[n - 2];
    for (int i = n - 3; i >= 0; i--)
        sub -= (long long) ratings[i];

    max_rating -= sub;

    std::cout << max_rating << "\n";
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