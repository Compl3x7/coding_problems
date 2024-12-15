#include <bits/stdc++.h>

void solve()
{
    std::string a;
    std::cin >> a;

    std::string b;
    for (int i = a.size() - 1; i >= 0; i--)
    {
        if (a[i] == 'p')
            b += 'q';
        else if (a[i] == 'q')
            b += 'p';
        else
            b += a[i];
    }

    std::cout << b << "\n";
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