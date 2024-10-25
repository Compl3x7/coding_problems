#include <bits/stdc++.h>

int search(std::vector<std::vector<int>> &matrix, int i, int j)
{
    int min = 0;
    for (int k = 0; std::max(i, j) + k < matrix.size(); k++)
        if (matrix[i + k][j + k] < min)
            min = matrix[i + k][j + k];

    return - min;
}

void solve()
{
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> matrix(n, std::vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            std::cin >> matrix[i][j];

    int count = 0;
    for (int j = n - 1; j >= 0; j--)
        count += search(matrix, 0, j);

    for (int i = 1; i < n; i++)
        count += search(matrix, i, 0);

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