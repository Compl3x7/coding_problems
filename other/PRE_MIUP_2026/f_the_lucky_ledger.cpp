#include <bits/stdc++.h>

int binary_search(std::vector<int> &a, int x)
{
    int low = 0;
    int high = a.size();
    int mid;
    while (low < high)
    {
        mid = low + (high - low) / 2;
        
        if (a[mid] >= x)
            high = mid;
        else
            low = mid + 1;
    }

    return low;
}

void solve()
{
    int n;
    int k;
    std::cin >> n >> k;

    std::vector<int> numbers(n);
    for (int i = 0; i < n; i++)
        std::cin >> numbers[i];

    std::unordered_map<long long, std::vector<int>> mapped_numbers;
    for (int i = 0; i < n; i++)
        mapped_numbers[(long long) numbers[i]].push_back(i);

    long long count = 0;
    for (int i = 0; i < n; i++)
    {
        if (numbers[i] % k != 0)
            continue;

        long long prev = (long long) numbers[i] / k;
        long long next = (long long) numbers[i] * k;
        bool contains_prev = mapped_numbers.find(prev) != mapped_numbers.end();
        bool contains_next = mapped_numbers.find(next) != mapped_numbers.end();

        if (contains_prev && contains_next)
        {
            int prev_index = binary_search(mapped_numbers[prev], i);          
            int next_index = binary_search(mapped_numbers[next], i + 1);

            count += (long long) prev_index * (mapped_numbers[next].size() - next_index);
        }
    }

    std::cout << count << "\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}