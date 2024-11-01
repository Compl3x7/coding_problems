#include <bits/stdc++.h>

void solve()
{
    int a;
    int b;
    std::cin >> a >> b;

    int x = b - a;
    if (x >= a)
        std::cout << 0 << "\n";
    else
        std::cout << std::min(a - x, a) << "\n";
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