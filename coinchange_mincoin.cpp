#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout << "Enter the total amount and how many coins in the set\n";
    int amt, n; cin >> amt >> n;

    int c[n];
    cout << "Enter Coins\n";
    for(int i = 0; i < n; i++) cin >> c[i];

    int sol[n + 1][amt + 1];
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= amt; j++)
        {
            if(j == 0) sol[i][j] = 0;
            else sol[i][j] = INT_MAX;
        }
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= amt; j++)
        {
            if(c[i - 1] > j) sol[i][j] = sol[i - 1][j];
            else sol[i][j] = min(sol[i - 1][j], 1 + sol[i][j - c[i - 1]]);
        }
    }

    if(sol[n][amt] == INT_MAX) cout << "No solution possible\n";
    cout << "Minimum coins: " << sol[n][amt] << "\n";

    return 0;
}

