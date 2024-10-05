#include <bits/stdc++.h>

void solve()
{
    int n;
    int k;
    std::cin >> n >> k;

    std::vector<int> gold(n);
    for (int i = 0; i < n; i++)
        std::cin >> gold[i];

    int count = 0;
    int held = 0;
    for (int i = 0; i < n; i++)
    {
        if (gold[i] >= k)
            held += gold[i];
        else if (gold[i] == 0 && held > 0)
        {
            held--;
            count++;
        }
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