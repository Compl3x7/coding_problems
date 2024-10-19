#include <bits/stdc++.h>

void solve()
{
    int n;
    std::cin >> n;

    int result = n / 10 + n % 10;
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