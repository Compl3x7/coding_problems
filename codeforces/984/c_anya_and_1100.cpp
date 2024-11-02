#include <bits/stdc++.h>

int find_1100_from(std::string &s, int i)
{
    if (i + 3 > s.length())
        return -1;

    if (s[i] == '1' && s[i + 1] == '1' && s[i + 2] == '0' && s[i + 3] == '0')
        return i;
    else
        return -1;
}

int count_all_1100(std::string &s)
{
    int count = 0;
    for (int i = 0; i < s.length() - 3; i++)
    {
        int found = find_1100_from(s, i);
        if (found != -1)
        {
            count++;
            i += 3;
        }
    }

    return count;
}

int contains_1100_within(std::string &s, int i)
{
    int count = 0;
    if (s[i] == '1')
    {
        int j = find_1100_from(s, i);
        if (j == -1)
            j = find_1100_from(s, i - 1);

        if (j != -1)
            count++;
    }
    else
    {
        int j = find_1100_from(s, i - 2);
        if (j == -1)
            j = find_1100_from(s, i - 3);

        if (j != -1)
            count++;
    }

    return count;
}

void solve()
{
    std::string s;
    std::cin >> s;

    int q;
    std::cin >> q;

    std::vector<std::pair<int, char>> queries(q);
    for (int i = 0; i < q; i++)
    {
        std::cin >> queries[i].first;
        std::cin >> queries[i].second;
    }

    int count = count_all_1100(s);
    for (int i = 0; i < q; i++)
    {
        int swap_index = queries[i].first - 1;

        if (s[swap_index] != queries[i].second)
        {
            count -= contains_1100_within(s, swap_index);
            s[swap_index] = queries[i].second;
            count += contains_1100_within(s, swap_index);
        }
            
        if (count)
            std::cout << "YES\n";
        else
            std::cout << "NO\n";
    }
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