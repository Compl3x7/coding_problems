#include <bits/stdc++.h>

void even_solve(std::vector<long long> &cells)
{
    long long max_dist = 1;
    for (int i = 1; i < cells.size(); i += 2)
    {
        long long curr_dist = cells[i] - cells[i - 1];
        if (curr_dist > max_dist)
            max_dist = curr_dist; 
    }

    std::cout << max_dist << "\n";
}

void odd_solve(std::vector<long long> &cells)
{
    long long min_max_dist = LONG_LONG_MAX;
    for (int i = 0; i < cells.size(); i += 2)
    {
        long long curr_max_dist = 1;
        for (int j = 1; j < i; j += 2)
        {
            long long curr_dist = cells[j] - cells[j - 1];
            if (curr_dist > curr_max_dist)
                curr_max_dist = curr_dist; 
        }

        for (int j = i + 2; j < cells.size(); j += 2)
        {
            long long curr_dist = cells[j] - cells[j - 1];
            if (curr_dist > curr_max_dist)
                curr_max_dist = curr_dist; 
        }

        if (curr_max_dist < min_max_dist)
            min_max_dist = curr_max_dist;
    }

    std::cout << min_max_dist << "\n";
}

void solve()
{
    int n;
    std::cin >> n;

    std::vector<long long> cells(n);
    for (int i = 0; i < n; i++)
        std::cin >> cells[i];

    long long max_dist = 1;
    if (n % 2 == 0)
        even_solve(cells);
    else
        odd_solve(cells);
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