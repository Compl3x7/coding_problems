#include <bits/stdc++.h>

void solve(std::string c, int d)
{
    int count = 0;
    int i = 0;
    while (i < c.length())
    {
        if (c[i] == 'F')
        {
            count++;
            i += d;
        }
        else
            i++;
    }

    std::cout << count << "\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    int t;
    std::cin >> t;

    std::vector<int> d(t);
    std::vector<std::string> c(t);
    for (int i = 0; i < t; i++)
    {
        std::cin >> d[i];
        std::cin >> c[i];
    }

    for (int i = 0; i < t; i++)
        solve(c[i], d[i]);

    return 0;
}