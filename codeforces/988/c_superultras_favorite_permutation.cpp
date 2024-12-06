#include <bits/stdc++.h>

void solve()
{
    int n;
    std::cin >> n;

    if (n <= 4)
    {
        std::cout << "-1\n";
        return;
    }

    std::vector<int> permutation(n);

    int term = 1;
    int left_size = n % 2 != 0 ? n / 2 : n / 2 - 1;
    int i = 0;
    while (i < left_size)
    {
        if (term != 5)
            permutation[i++] = term;
        term += 2;
    }

    permutation[i++] = 5;
    permutation[i++] = 4;

    term = 2;
    while (i < n)
    {
        if (term != 4)
            permutation[i++] = term;
        term += 2;
    }

    for (int i = 0; i < n - 1; i++)
        std::cout << permutation[i] << " ";
    std::cout << permutation[n - 1] << "\n";
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