#include <bits/stdc++.h>

void solve()
{
    int n;
    int m;
    int l;
    std::cin >> n >> m >> l;

    std::vector<std::pair<int, int>> hurdles(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> hurdles[i].first;
        std::cin >> hurdles[i].second;
    }

    std::vector<std::pair<int, int>> power_ups(m);
    for (int i = 0; i < m; i++)
    {
        std::cin >> power_ups[i].first;
        std::cin >> power_ups[i].second;
    }

    int count = 0;
    long long power = 1;
    int j = 0;
    std::priority_queue<int> power_ups_up_to_hurdle;
    for (int i = 0; i < n; i++)
    {
        while (power_ups[j].first < hurdles[i].first && j < m)
            power_ups_up_to_hurdle.push(power_ups[j++].second);

        long long hurdle_len = hurdles[i].second - hurdles[i].first + 1;
        while (power <= hurdle_len)
        {
            if (power_ups_up_to_hurdle.empty())
            {
                std::cout << "-1\n";
                return;
            }

            power += (long long) power_ups_up_to_hurdle.top();
            power_ups_up_to_hurdle.pop();
            count++;
        }
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