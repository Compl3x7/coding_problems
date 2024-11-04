#include <bits/stdc++.h>

void solve()
{
    int n;
    int q;
    std::cin >> n >> q;

    std::vector<int> points(n);
    for (int i = 0; i < n; i++)
        std::cin >> points[i];

    std::vector<long long> queries(q);
    for (int i = 0; i < q; i++)
        std::cin >> queries[i];

    std::unordered_map<long long, int> map;
    int i = 0;
    int j = i;
    while (points[0] + i <= points[n - 1])
    {   
        int n_points = 1;
        long long count = (long long) (n - j) * j;
        if (points[0] + i == points[j])
            count += (long long) n - ++j;
        else
            n_points = points[j] - (points[0] + i);
     
        map[count] += n_points;
        i += n_points;
    }

    for (int i = 0; i < q - 1; i++)
        std::cout << map[queries[i]] << " ";
    std::cout << map[queries[q - 1]] << "\n";
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