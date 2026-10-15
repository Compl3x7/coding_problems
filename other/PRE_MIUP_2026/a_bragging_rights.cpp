#include <bits/stdc++.h>

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> pirates(n);
    for (int i = 0; i < n; i++)
        std::cin >> pirates[i];


    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> min_heap;
    for (int i = 0; i < n; i++)
    {
        min_heap.push({pirates[i], i});
        if (min_heap.size() > 2)
            min_heap.pop();
    }

    std::pair<int, int> max2 = min_heap.top();
    min_heap.pop();
    std::pair<int, int> max1 = min_heap.top(); 

    std::vector<int> diff(n);

    for (int i = 0; i < n; i++)
    {
        if (i == max1.second)
            diff[i] = pirates[i] - max2.first;
        else
            diff[i] = pirates[i] - max1.first;
    }

    for (int i = 0; i < n - 1; i++)
        std::cout << diff[i] << " ";

    std::cout << diff[n - 1] << "\n";
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