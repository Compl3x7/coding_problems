#include <bits/stdc++.h>

void solve(std::vector<int> &stickers, std::vector<int> &wanted)
{
    std::unordered_map<int, int> map;
    for (int i = 0; i < stickers.size(); i++)
        map[stickers[i]]++;

    int count = 0;
    for (int i = 0; i < wanted.size(); i++)
        count += map[wanted[i]];

    std::cout << count << "\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    int n;
    std::cin >> n;

    std::vector<int> stickers(n);
    for (int i = 0; i < n; i++)
        std::cin >> stickers[i];

    int m;
    std::cin >> m;

    std::vector<int> wanted(m);
    for (int i = 0; i < m; i++)
        std::cin >> wanted[i];

    solve(stickers, wanted);
    
    return 0;
}