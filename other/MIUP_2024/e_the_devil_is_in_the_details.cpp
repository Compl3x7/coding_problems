#include <bits/stdc++.h>

void solve()
{
    int e;
    int t;
    std::cin >> e >> t;

    std::vector<std::vector<int>> logs(t, std::vector<int>(e));
    for (int i = 0; i < t; i++)
        for (int j = 0; j < e; j++)
            std::cin >> logs[i][j];

    int k = 0;
    for (int j = 0; j < e; j++)
        k += logs[0][j];

    for (int i = 1; i < t; i++)
    {
        int curr_k = 0;
        for (int j = 0; j < e; j++)
            curr_k += logs[i][j];

        if (curr_k != k)
        {
            std::cout << "Maxwell daemon!\n";
            return;
        }
    }

    std::cout << "Total energy is " << k << ", no physical law broken.\n";
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