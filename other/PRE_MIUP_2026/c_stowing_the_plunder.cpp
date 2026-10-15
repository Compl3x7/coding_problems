#include <bits/stdc++.h>

void solve(int n, int m)
{
    std::vector<int> bundles(n);
    std::vector<int> chests(m);

    for (int i = 0; i < n; i++)
        std::cin >> bundles[i];

    for (int i = 0; i < m; i++)
        std::cin >> chests[i];

    std::sort(bundles.begin(), bundles.end());
    std::sort(chests.begin(), chests.end());

    int i = 0;
    int j = 0;
    int sum = 0;
    while (i < n && j < m)
    {
        if (bundles[i] <= chests[j])
        {
            sum += chests[j];
            i++;
        }
        j++;
    }

    if (i < bundles.size())
        std::cout << "Impossible\n";
    else
        std::cout << sum << "\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    while (true)
    {
        int n;
        int m;
        std::cin >> n >> m;

        if (n == 0 && m == 0)
            break;

        solve(n, m);
    }
    return 0;
}