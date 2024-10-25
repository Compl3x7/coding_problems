#include <bits/stdc++.h>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int m;
    int n;
    std::cin >> m >> n;

    std::vector<int> alice(m);
    for (int i = 0; i < m; i++)
        std::cin >> alice[i];

    std::vector<int> bob(n);
    for (int i = 0; i < n; i++)
        std::cin >> bob[i];

    long long alice_expected = 0;
    for (int i = 0; i < m; i++)
        alice_expected += (long long) alice[i] + 1;

    long long bob_expected = 0;
    for (int i = 0; i < n; i++)
        bob_expected += (long long) bob[i] + 1;

    if (alice_expected > bob_expected)
        std::cout << "ALICE\n";
    else if (alice_expected < bob_expected)
        std::cout << "BOB\n";
    else
        std::cout << "TIED\n";
}