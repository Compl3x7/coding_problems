#include <bits/stdc++.h>

int log(int base, int n)
{
    int result = 0;
    while (n >= base)
    {
        n /= base;
        result++;
    }
    return result;
}

long long pow(int base, int exp)
{
    long long result = 1;
    while (exp-- > 0)
        result *= (long long) base;
    
    return result;
}

int binary_search(int low, int high, long long p, int x)
{
    int mid;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        
        if ((long long) mid * p == x)
            break;
        if ((long long) mid * p > x)
            high = mid - 1;
        else
            low = mid + 1;
    }

    return mid;
}

void solve()
{
    int k;
    int l1;
    int r1;
    int l2;
    int r2;
    std::cin >> k >> l1 >> r1 >> l2 >> r2;

    int min = l2 / r1;
    if (l2 % r1 != 0)
        min++;
    int max = r2 / l1;

    int exp = log(k, min);
    long long p = pow(k, exp);
    long long count = 0;
    while (p <= max)
    {
                
        int max_x = binary_search(l1, r1, p, r2);
        int min_x = binary_search(l1, r1, p, l2);
        if ((long long) max_x * p > r2)
            max_x--;
        if ((long long) min_x * p < l2)
            min_x++;

        long long dist = (long long) std::max(max_x - min_x, -1);
        count += dist + 1;

        p *= (long long) k;
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