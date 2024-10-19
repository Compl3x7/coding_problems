#include <bits/stdc++.h>
    
void solve()
{
    int n;
    int k;
    std::cin >> n >> k;
    
    std::vector<int> cards(n);
    for (int i = 0; i < n; i++)
        std::cin >> cards[i];
    
    std::sort(cards.begin(), cards.end());
    int max_cards = 0;
    int j = 0;
    for (int i = 0; i < n || j < n - 1; i++)
    {
        for (j = std::max(i, j); j < n - 1; j++)
            if (cards[j + 1] > cards[j] + 1  || cards[j + 1] >= cards[i] + k)
                break;
        max_cards = std::max(j - i + 1, max_cards);
    }
    
    std::cout << max_cards << "\n";
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
