#include <bits/stdc++.h>

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    int odd_max = 0;
    int even_max = 0;
    for (int i = 0; i < n; i += 2)
    {
        if (a[i] > even_max)
            even_max = a[i];
        if (i + 1 < n && a[i + 1] > odd_max)
            odd_max = a[i + 1];
    }

    int div_2 = n / 2;
    int mod_2 = n % 2;
    odd_max += div_2;
    even_max += div_2 + mod_2;
    int result = odd_max > even_max ? odd_max : even_max;
    
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