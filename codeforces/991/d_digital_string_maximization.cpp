#include <bits/stdc++.h>

void solve()
{
    std::string s;
    std::cin >> s;

    for (int i = 0; i < s.size(); i++)
    {
        char max = '0';
        int max_j = i;
        for (int j = 0; j < 10 && i + j < s.size(); j++)
            if (s[i + j] - j > max)
            {
                max = s[i + j] - j;
                max_j = i + j;
            }

        s[max_j] = max;
        while (max_j > i)
        {
            char temp = s[max_j];
            s[max_j] = s[max_j - 1];
            s[max_j - 1] = temp;
            max_j--;
        }
    }

    std::cout << s << "\n";
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