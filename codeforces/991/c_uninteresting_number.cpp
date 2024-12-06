#include <bits/stdc++.h>

void solve()
{
    std::string number;
    std::cin >> number;

    int a = 0;
    int b = 0;
    int sum = 0;
    for (int i = 0; i < number.size(); i++)
    {
        if (number[i] == '2')
            a++;
        if (number[i] == '3')
            b++;

        sum += (number[i] - '0');
    }

    for (int a_count = 0; a_count <= a; a_count++)
        for (int b_count = 0; b_count <= b; b_count++)
        {
            int new_sum = sum + a_count * 2 + b_count * 6;
            if (new_sum % 9 == 0)
            {
                std::cout << "YES\n";
                return;
            }
        }

    std::cout << "NO\n";
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