#include <bits/stdc++.h>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    int t;
    std::cin >> t;
    
    std::vector<int> n(t);
    for (int i = 0; i < t; i++)
        std::cin >> n[i];
    
    std::vector<int> k(t);
    for (int i = 0; i < t; i++)
        std::cin >> k[i];
    
    int max = 0;
    for (int i = 0; i < t; i++)
        if (k[i] > max)
            max = k[i];

    int mod = 1000000007;
    std::vector<int> powers(max);
    powers[0] = 2;
    for (int i = 1; i < max; i++)
        powers[i] = (powers[i - 1] * 2) % mod;

    for (int i = 0; i < t; i++)
        std::cout << powers[k[i] - 1] << "\n";

    return 0;
}