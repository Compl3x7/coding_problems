#include <bits/stdc++.h>

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> notes(n);
    for (int i = 0; i < n; i++)
        std::cin >> notes[i];

    for (int i = 1; i < n; i++)
    {
        int seminote = std::abs(notes[i] - notes[i - 1]);
        if (seminote != 7 && seminote != 5)
        {
            std::cout << "NO\n";
            return;
        }
    }

    std::cout << "YES\n";
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