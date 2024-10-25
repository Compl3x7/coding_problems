#include <bits/stdc++.h>

void solve()
{
    int n;
    std::cin >> n;

    std::cout << (n % 2 == 0 ? "Sakurako\n" : "Kosuke\n");
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