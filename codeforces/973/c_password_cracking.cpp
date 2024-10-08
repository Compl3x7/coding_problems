#include <bits/stdc++.h>

bool valid(std::string &s, std::vector<std::string> &cache)
{
    for (std::string sub : cache)
        if (s.find(sub) != std::string::npos)
            return false;
    
    return true;
}

int query(std::string &curr, std::string &temp, std::vector<std::string> &cache)
{
    if (!valid(temp, cache))
        return 0;

    std::cout << "? " << temp << std::endl;

    int answer;
    std::cin >> answer;
    if (answer)
        curr = temp;             
    else
        cache.push_back(temp);

    return answer;
}

void solve()
{
    int n;
    std::cin >> n;

    std::string curr = "";
    std::vector<std::string> cache;
    int answer;
    while (curr.length() < n && answer != -1)
    {
        std::string temp[4] = {curr + "0", curr + "1", "0" + curr, "1" + curr}; 
        for (std::string s : temp)
            if ((answer = query(curr, s, cache)) == 1)
                break;
    }

    std::cout << "! " << curr << std::endl;    
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    
    int t;
    std::cin >> t;
    while (t--)
        solve();

    return 0;
}