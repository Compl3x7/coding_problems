#include <bits/stdc++.h>

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::map<int, int> map;
    for (int i = 0; i < n; i++)
        map[a[i]]++;

    int score = 0;
    for (std::map<int, int>::iterator it = map.begin(); it != map.end(); it++)
        score += it->second / 2;
        
    std::cout << score << "\n";
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