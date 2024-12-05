#include <bits/stdc++.h>

int dfs(int curr, int from, std::unordered_map<int, std::vector<int>> &tree)
{

    int degree = tree[curr].size();
    int leaf_count = degree > 1 ? 0 : 1;

    for (int i = 0; i < tree[curr].size(); i++)
        if (tree[curr][i] != from)
            leaf_count += dfs(tree[curr][i], curr, tree);

    return leaf_count;
}


void solve()
{
    int n;
    int p;
    std::cin >> n >> p;

    std::unordered_map<int, std::vector<int>> tree;
    for (int i = 0; i < n - 1; i++)
    {
        int from;
        int to;
        std::cin >> from >> to;
        tree[from].push_back(to);
        tree[to].push_back(from);
    }

    int leaf_count = dfs(0, n, tree); // N is never a valid node

    int result = 2 * (p / leaf_count) + std::min(2, p % leaf_count);
    std::cout << result << "\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}