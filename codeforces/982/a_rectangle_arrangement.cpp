#include <bits/stdc++.h>

void solve()
{
    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> rectangles(n);
    for (int i = 0; i < n; i++)
        std::cin >> rectangles[i].first >> rectangles[i].second;

    int max_w = 0;
    int max_h = 0;
    for (int i = 0; i < n; i++)
    {
        if (rectangles[i].first > max_w)
            max_w = rectangles[i].first;
        if (rectangles[i].second > max_h)
            max_h = rectangles[i].second;
    }

    int perimeter = 2 * max_w + 2 * max_h;
    std::cout << perimeter << "\n";
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