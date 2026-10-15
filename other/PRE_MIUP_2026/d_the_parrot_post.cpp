#include <bits/stdc++.h>

int furthest_node(int from, std::unordered_map<int, std::vector<int>> &tree)
{
    std::queue<int> queue;
    std::unordered_set<int> closed;

    int curr = from;
    queue.push(curr);
    while (!queue.empty())
    {
        curr = queue.front();
        queue.pop();

        for (int i = 0; i < tree[curr].size(); i++)
            if (closed.find(tree[curr][i]) == closed.end())
                queue.push(tree[curr][i]);

        closed.insert(curr);
    }

    return curr;
}

int max_depth(int curr, int prev, std::unordered_map<int, std::vector<int>> &tree)
{
    int depth = 0;

    for (int i = 0; i < tree[curr].size(); i++)
        if (tree[curr][i] != prev)
            depth = std::max(1 + max_depth(tree[curr][i], curr, tree), depth);

    return depth;
}

void solve()
{
    int n;
    std::cin >> n;

    std::unordered_map<int, std::vector<int>> tree;
    for (int i = 0; i < n - 1; i++)
    {
        int from;
        int to;
        std::cin >> from >> to;
        tree[from].push_back(to);
        tree[to].push_back(from);
    }

    int result;
    if (n < 4)
        result = 1;
    else
    {
        int start_node = furthest_node(0, tree);
        int cost = max_depth(start_node, -1, tree);
        result = cost / 2 + cost % 2;
    }

    std::cout << result << "\n";
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