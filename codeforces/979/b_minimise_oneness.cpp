#include <bits/stdc++.h>

void solve()
{
    int n;
    std::cin >> n;

    std::string result = "0";
    for (int i = 1; i < n; i++)
        if (i == n - 1)
            result += "1";
        else
            result += "0";
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