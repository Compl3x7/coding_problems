#include <bits/stdc++.h>

void solve()
{
    std::string s;
    std::string t;
    std::cin >> s >> t;

    int common_prefix_count = 0;

    for (int i = 0; i < s.length() && i < t.length(); i++)
        if (s[i] == t[i])
            common_prefix_count++;
        else 
            break;
    
    int seconds = common_prefix_count + (s.length() - common_prefix_count) + (t.length() - common_prefix_count);
    if (common_prefix_count > 0)
        seconds++;

    std::cout << seconds << "\n";
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