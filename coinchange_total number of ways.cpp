#include <bits/stdc++.h>
using namespace std;
int main()
{
    cout << "Enter the total amount and how many coins in the set\n";
    int amt, n; cin >> amt >> n;

    int c[n];
    cout << "Enter Coins\n";
    for(int i = 0; i < n; i++) cin >> c[i];
  
    int solution[n + 1][amt + 1];

    // Initialize the solution table
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= amt; j++)
        {
            if (j == 0) solution[i][j] = 1;
            else solution[i][j] = 0;
        }
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= amt; j++)
        {
            if (c[i - 1] > j) solution[i][j] = solution[i - 1][j];
            else solution[i][j] = solution[i - 1][j] + solution[i][j - c[i - 1]];
        }
    }
    cout << "Total number of ways to make the amount: " << solution[n][amt] << "\n";
  
    return 0;
}
