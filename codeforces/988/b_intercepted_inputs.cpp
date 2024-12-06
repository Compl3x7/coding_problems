#include <bits/stdc++.h>

void solve()
{
    int k;
    std::cin >> k;

    std::vector<int> stream(k);
    for (int i = 0; i < k; i++)
        std::cin >> stream[i];

    int target = k - 2;
    std::set<int> values;
    for (int i = 0; i < k; i++)
    {
        if (target % stream[i] != 0)
            continue;
            
        int complement = target / stream[i];
        if (values.count(complement))
        {
            std::cout << stream[i] << " " << complement << "\n";
            return;
        }

        values.insert(stream[i]);
    }
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