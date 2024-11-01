#include <bits/stdc++.h>

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> circuit(2 * n);

    for (int i = 0; i < 2 * n; i++)
        std::cin >> circuit[i];

    int one_count = 0;
    int zero_count = 0;
    for (int i = 0; i < 2 * n; i++)
        if (circuit[i])
            one_count++;
        else
            zero_count++;

    int min = one_count % 2;
    int max = n - (std::abs(one_count - zero_count) / 2);

    std::cout << min << " " << max << "\n";
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