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
    for (int i = 0; i < left_size; i++)
    {
        if (term != 5)
            permutation[i] = term;
        else
            i--; //hack ;( i'm sad
        term += 2;
    }

    permutation[left_size] = 5;
    permutation[left_size + 1] = 4;

    term = 2;
    for (int i = left_size + 2; i < n; i++)
    {
        if (term != 4)
            permutation[i] = term;
        else
            i--; //hack ;( i'm sad
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