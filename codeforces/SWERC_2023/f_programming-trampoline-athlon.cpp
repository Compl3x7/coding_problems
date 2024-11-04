#include <bits/stdc++.h>

void solve(std::vector<std::pair<std::string, int[7]>> &teams)
{
    std::vector<std::pair<std::string, int>> scores(teams.size());
    for (int i = 0; i < teams.size(); i++)
    {
        scores[i].first = teams[i].first;
        scores[i].second = teams[i].second[0] * 10;

        int min_score = 10;
        int max_score = 0;
        int total_score = 0;
        for (int j = 1; j < 7; j++)
        {
            if (teams[i].second[j] < min_score)
                min_score = teams[i].second[j];
            if (teams[i].second[j] > max_score)
                max_score = teams[i].second[j];
            
            total_score += teams[i].second[j];
        }
        total_score -= max_score + min_score;

        scores[i].second += total_score;
    }

    std::priority_queue<int, std::vector<int>, std::greater<>> min_heap;
    for (int i = 0; i < teams.size(); i++)
    {
        min_heap.push(scores[i].second);
        if (min_heap.size() > 3)
            min_heap.pop();
    }

    std::vector<int> best_scores(3);
    int index = 2;
    while (!min_heap.empty())
    {
        best_scores[index--] = min_heap.top();
        min_heap.pop();
    }

    for (int i = 0; i < 3; i++)
        if (i == 0 || best_scores[i] != best_scores[i - 1])
            for (int j = 0; j < scores.size(); j++)
                if (scores[j].second == best_scores[i])
                    std::cout << scores[j].first << " " << scores[j].second << "\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    int n;
    std::cin >> n;

    std::vector<std::pair<std::string, int[7]>> teams(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> teams[i].first;
        for (int j = 0; j < 7; j++)
            std::cin >> teams[i].second[j];
    }

    solve(teams);

    return 0;
}