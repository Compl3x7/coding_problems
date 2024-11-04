#include <bits/stdc++.h>

// I don't like this problem :/, but someone will :D
    
bool on_layer_corner(int i, int j, int n, int m, int layer)
{
    return (j == layer && i == layer) || 
            (j == m - layer - 1 && i == layer) ||
            (j == m - layer - 1 && i == n - layer - 1) || 
            (j == layer && i == n - layer - 1);
}
    
void iterate(int &i, int &j, int &direction, int n, int m, int layer)
{
    if (direction == 0)
        j++;
    else if (direction == 1)
        i++;
    else if (direction == 2)
        j--;
    else if (direction == 3)
        i--;
    
    if (on_layer_corner(i, j, n, m, layer))
    {
        direction++;
        direction %= 4;
    }
}

int find_1543_from(std::vector<std::string> &carpet, int &i, int &j, int &direction, int layer, int &k)
{
    int i_val = i;
    int j_val = j;
    int direction_val = direction;

    std::string s = "1543";
    for (int l = 0; l < 4; l++)
    {
        if (s[l] != carpet[i][j])
        {
            // Backtrack to previous values
            i = i_val;
            j = j_val;
            direction = direction_val;
            return 0;
        }
    
        iterate(i, j, direction, carpet.size(), carpet[i].size(), layer);
    }   
    
    k += 3;
    return 1;
}
    
void solve()
{
    int n;
    int m;
    std::cin >> n >> m;
    
    std::vector<std::string> carpet(n);
    for (int i = 0; i < n; i++)
        std::cin >> carpet[i];
    
    int layers = std::min(n, m) / 2;
    int count = 0;
    for (int layer = 0; layer < layers; layer++)
    {
        int i = layer;
        int j = layer;
        int layer_size = 2 * ((n - 2 * layer) + (m - 2 * layer) - 2);
        int direction = 0;
        for (int k = 0; k < layer_size; k++)
        {
            int found = find_1543_from(carpet, i, j, direction, layer, k);
            count += found;
            //If we found, find_1543_from() put us at the next iteration's index already, no need to iterate again
            if (!found)
                iterate(i, j, direction, n, m, layer);
        }
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