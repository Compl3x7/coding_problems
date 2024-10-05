#include <bits/stdc++.h>

void solve()
{
    int n;
    int k;
    std::cin >> n >> k;

    bool spawned_even = ((n + n % 2) / 2) % 2 == 0;
    int dead_base = n - k;
    bool died_even = ((dead_base + dead_base % 2) / 2) % 2 == 0;

    std::cout << (spawned_even == died_even ? "YES" : "NO") << "\n";
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