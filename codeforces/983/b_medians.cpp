#include <bits/stdc++.h>

void solve()
{
    int n;
    int k;
    std::cin >> n >> k;

    int m;
    std::vector<int> result;
    if (n == 1)
    {
        m = 1;
        result.push_back(1);
    }
    else if ((n - k) % 2 != 0)
    {
        m = 3;
        result.push_back(1);
        result.push_back(k);
        result.push_back(k + 1);
    }
    else if (n - k > 0 && k > 1)
    {
        m = 5;
        result.push_back(1);
        result.push_back(2);
        result.push_back(k);
        result.push_back(k + 1);
        result.push_back(k + 2);  
    }
    else
        m = -1;

    std::cout << m << "\n";
    if (m != -1)
    {
        for (int i = 0; i < m - 1; i++)
            std::cout << result[i] << " ";
        std::cout << result[m - 1] << "\n";
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