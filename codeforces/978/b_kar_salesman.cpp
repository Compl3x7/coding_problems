#include <bits/stdc++.h>

void solve()
{
    int n;
    int x;
    std::cin >> n >> x;

    std::vector<int> cars(n);
    for (int i = 0; i < n; i++)
        std::cin >> cars[i];

    long long max = 0;
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += (long long) cars[i];
        if (cars[i] > max)
            max = cars[i];
    }

    long long div = sum / (long long) x;
    if (sum % x != 0)
        div++;

    long long days = std::max(max, div);
    std::cout << days << "\n";
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