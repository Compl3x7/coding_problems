#include <bits/stdc++.h>

void solve()
{
    int x;
    int y;
    int k;
    std::cin >> x >> y >> k;

    int min = std::min(x, y);

    int ab[4] = {0, 0, min, min};
    int cd[4] = {0, min, min, 0};
    for (int i = 0; i < 3; i++)
        std::cout << ab[i] << " ";
    std::cout << ab[3] << "\n";

    for (int i = 0; i < 3; i++)
        std::cout << cd[i] << " ";
    std::cout << cd[3] << "\n";
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