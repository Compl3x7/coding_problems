#include <bits/stdc++.h>

void solve()
{
    int d;
    char c[1000];
    std::cin >> d >> c;

    int count = 0;
    int i = 0;
    while (c[i])
    {
        if (c[i] == 'F')
        {
            count++;
            i += d;
        }
        else if (c[i] == '.')
            i++;
    }

    std::cout << count << "\n";
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