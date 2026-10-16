#include <bits/stdc++.h>

void solve()
{
    int n;
    int m;
    int q;
    std::cin >> n >> m >> q;

    std::vector<std::string> barrels(n);
    for (int i = 0; i < n; i++)
        std::cin >> barrels[i];

    std::vector<int> queries(q);
    for (int i = 0; i < q; i++)
        std::cin >> queries[i];

    std::vector<int> safe_count(n);
    for (int j = 0; j < m; j++)
    {
        int i = n - 1;
        int curr_instant = 0;
        while (i >= 0 && curr_instant < safe_count.size())
        {
            int count = 0;
            while (i >= 0 && barrels[i][j] == '*')
            {
                count++;
                i--;
            }

            safe_count[curr_instant++] += count;
            i--; // Altough i can go to negative, it doesn't matter  
        }
    }    

    for (int i = 1; i < safe_count.size(); i++)
        safe_count[i] += safe_count[i - 1];

    for (int i = 0; i < q; i++)
        std::cout << safe_count[std::min(queries[i], n - 1)] << "\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}