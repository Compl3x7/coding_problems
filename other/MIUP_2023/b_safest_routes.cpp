#include <bits/stdc++.h>

void solve(std::vector<std::vector<std::pair<int, int>>> &graph, int from, int to)
{
    std::vector<int> cost(graph.size(), INT_MAX);
    std::priority_queue<std::pair<int, int>> open;

    open.push({0, from});
    cost[from] = 0;

    while (!open.empty())
    {
        std::pair<int, int> curr = open.top();
        open.pop();

        if (curr.second == to)
        {
            std::cout << cost[to] << "\n";
            return;
        }

        for (std::pair<int, int> edge : graph[curr.second])
            if (cost[curr.second] + edge.first < cost[edge.second])
            {
                cost[edge.second] = cost[curr.second] + edge.first;
                open.push({-cost[edge.second], edge.second});
            }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    int q;
    int s;
    int t;
    std::cin >> q >> s >> t;

    std::vector<std::vector<std::pair<int, int>>> graph(q, std::vector<std::pair<int, int>>());
    while (s--)
    {
        int from;
        int to;
        int weight;
        std::cin >> from >> to >> weight;

        graph[from].push_back({0, to});
        graph[to].push_back({weight, from});
    }

    std::vector<int> from(t);
    std::vector<int> to(t);
    for (int i = 0; i < t; i++)
    {
        std::cin >> from[i];
        std::cin >> to[i];
    }

    for (int i = 0; i < t; i++)
        solve(graph, from[i], to[i]);

    return 0;
}