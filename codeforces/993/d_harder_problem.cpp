#include <bits/stdc++.h>

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::vector<int> b(n);
    std::unordered_set<int> not_in_b;
    while (not_in_b.size() < n)
        not_in_b.insert(not_in_b.size() + 1);
    
    for (int i = 0; i < n; i++)
        if (not_in_b.contains(a[i]))
        {
            b[i] = a[i];
            not_in_b.erase(a[i]);
        }

    std::unordered_set<int>::iterator it = not_in_b.begin();
    for (int i = 0; i < n; i++)
        if (b[i] == 0)
        {
            b[i] = *it;
            it++;
        }

    for (int i = 0; i < n - 1; i++)
        std::cout << b[i] << " ";
    std::cout << b[n - 1] << "\n";
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