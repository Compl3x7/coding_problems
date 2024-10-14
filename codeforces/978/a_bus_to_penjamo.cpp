#include <bits/stdc++.h>

void solve()
{
    int n;
    int r;
    std::cin >> n >> r;
    
    std::vector<int> families(n);
    for (int i = 0; i < n; i++)
        std::cin >> families[i];

    int happy_count = 0;
    int left_out = 0;
    for (int i = 0; i < n; i++)
    {
        int filled_rows = families[i] / 2;
        r -= filled_rows;
        happy_count += filled_rows * 2;
        left_out += families[i] % 2;
    }

    if (r >= left_out)
        happy_count += left_out;
    else
        happy_count += (2 * r - left_out);

    std::cout << happy_count << "\n";
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