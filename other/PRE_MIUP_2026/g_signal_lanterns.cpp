#include <bits/stdc++.h>

void dfs(int curr, std::unordered_map<int, std::vector<int>> &graph, std::unordered_set<int> &closed)
{
    closed.insert(curr);

    for (int i = 0; i < graph[curr].size(); i++)
        if (closed.find(graph[curr][i]) == closed.end())
            dfs(graph[curr][i], graph, closed);
}

void solve()
{
    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> ships(n);
    for (int i = 0; i < n; i++)
        std::cin >> ships[i].first >> ships[i].second;

    std::unordered_map<int, int> row_anchors;
    std::unordered_map<int, int> column_anchors;
    std::unordered_map<int, std::vector<int>> graph;

    for (int i = 0; i < n; i++)
    {
        bool new_row = row_anchors.find(ships[i].first) == row_anchors.end();
        bool new_column = column_anchors.find(ships[i].second) == column_anchors.end();

        if (new_row)
            row_anchors[ships[i].first] = i;
        else
        {
            graph[i].push_back(row_anchors[ships[i].first]);
            graph[row_anchors[ships[i].first]].push_back(i);
        }

        if (new_column)
            column_anchors[ships[i].second] = i;
        else
        {
            graph[i].push_back(column_anchors[ships[i].second]);
            graph[column_anchors[ships[i].second]].push_back(i);
        }
    }

    std::unordered_set<int> closed;
    int result = -1;
    for (int i = 0; i < n; i++)
        if (closed.find(i) == closed.end())
        {
            dfs(i, graph, closed);
            result++;
        }

    std::cout << result << "\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
