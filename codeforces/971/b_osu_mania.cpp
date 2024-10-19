#include <bits/stdc++.h>

void solve()
{
    int n;
    std::cin >> n;

    std::vector<std::string> beatmap(n);
    for (int i = 0; i < n; i++)
        std::cin >> beatmap[i];

    std::vector<int> hits(n);
    for (int i = n - 1; i >= 0; i--)
        for (int j = 0; j < 4; j++)
            if (beatmap[i][j] == '#')
            {
                hits[n - i - 1] = j + 1;
                break;
            }

    for (int i = 0; i < n - 1; i++)
        std::cout << hits[i] << " ";
    std::cout << hits[n - 1] << "\n";
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