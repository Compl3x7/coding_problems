#include <bits/stdc++.h>

int log(int base, int n)
{
    long long result = 0;
    while (n >= base)
    {
        n /= base;
        result++;
    }
    return result;
}

int pow(int base, int exp)
{
    long long result = 1;
    while (exp-- > 0)
        result *= base;
    
    return result;
}

void solve()
{
    int n;
    int k;
    std::cin >> n >> k;

    int exp = k == 1 ? 0 : log(k, n); //:tf:
    int powk;
    int count = 0;
    while (exp >= 0)
    {
        powk = pow(k, exp--);
        count += n / powk;
        n = n % powk;
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