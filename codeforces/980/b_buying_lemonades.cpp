#include <bits/stdc++.h>

void solve()
{
    int n;
    int k;
    std::cin >> n >> k;

    std::vector<int> slots(n);
    for (int i = 0; i < n; i++)
        std::cin >> slots[i];

    long long lemonades = 0;
    long long count = 0;
    int j = 0;
    std::sort(slots.begin(), slots.end());
    for (int i = 1; i < n && lemonades < k; i++)
        if (slots[i] != slots[j])
        {
            int buffer = j > 0 ? slots[j] - slots[j - 1] - 1: slots[j];
            long long sum = (long long) buffer * (n - j);
            lemonades += sum;
            count += sum;
            if (lemonades < k)
            {
                lemonades += n - i;
                count += n - j;
            }
            j = i;
        }

    if (lemonades < k)
        count += k - lemonades;
    else
        count -= lemonades - k;

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