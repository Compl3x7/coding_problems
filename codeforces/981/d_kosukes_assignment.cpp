#include <bits/stdc++.h>

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    int count = 0;
    long long curr_sum = 0;
    // std::unordered_set<int> prev_sums; I learnt about hash hacking the hard way :(
    std::set<long long> prev_sums;
    for (int i = 0; i < n; i++)
    {
        curr_sum += (long long) a[i];
        if (curr_sum == 0 || prev_sums.contains(curr_sum))
        {
            count++;
            prev_sums.clear();
            curr_sum = 0;
        }
        else
            prev_sums.insert(curr_sum);
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