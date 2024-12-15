#include <bits/stdc++.h>

void solve()
{
    int m;
    int a;
    int b;
    int c;
    std::cin >> m >> a >> b >> c;

    int result = std::min(m, a) + std::min(m, b);
    result = std::min(result + c, 2 * m);

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