#include <bits/stdc++.h>
    
void solve()
{
    int n;
    int k;
    std::cin >> n >> k;
    
    std::vector<std::pair<int, int>> bottles(k);
    for (int i = 0; i < k; i++)
    {
        std::cin >> bottles[i].first;
        std::cin >> bottles[i].second;
    }
    
    std::map<int, int> map;
    for (int i = 0; i < k; i++)
        map[bottles[i].first] += bottles[i].second;
    
    std::vector<int> cost(map.size());
    int i = 0;
    for (std::map<int, int>::iterator it = map.begin(); it != map.end(); it++)
        cost[i++] = it->second;
        
    std::sort(cost.begin(), cost.end(), std::greater<>());
    int max = 0;
    for (int i = 0; i < std::min(n, (int) map.size()); i++)
        max += cost[i];
    
    std::cout << max << "\n";
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