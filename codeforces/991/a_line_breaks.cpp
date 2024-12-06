#include <bits/stdc++.h>

void solve()
{
    int n;
    int m;
    std::cin >> n >> m;

    std::vector<std::string> words(n);
    for (int i = 0; i < n; i++)
        std::cin >> words[i];

    int count = 0;
    int size = 0;
    for (int i = 0; i < n; i++)
    {
        size += words[i].size();
        if (size > m)
            break;
        
        count++;
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