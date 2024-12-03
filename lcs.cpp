#include <bits/stdc++.h>
using namespace std;

int LCS(string s1, string s2, int x, int y, vector<vector<int>> &c)
{
    for(int i = 1; i <= x; i++)
    {
        for(int j = 1; j <= y; j++)
        {
            if(s1[i - 1] == s2[j - 1]) c[i][j] = c[i - 1][j - 1] + 1;
            else c[i][j] = max(c[i][j - 1], c[i - 1][j]);
        }
    }
    return c[x][y];
}

string getLCS(string s1, string s2, int x, int y, vector<vector<int>> &c)
{
    string lcs;
    int i = x, j = y;
    while(i > 0 && j > 0)
    {
        if(s1[i - 1] == s2[j - 1])
        {
            lcs += s1[i - 1];
            i--;
            j--;
        }
        else if(c[i - 1][j] >= c[i][j - 1]) i--;
        else j--;
    }
    reverse(lcs.begin(), lcs.end());
    return lcs;
}

void printTable(const vector<vector<int>> &c, int x, int y)
{
    for(int i = 0; i <= x; i++)
    {
        for(int j = 0; j <= y; j++) cout << c[i][j] << " ";
        cout << '\n';
    }
}

int main()
{
    string s1 = "BDCABA";
    string s2 = "ABCBDAB";
    int x = s1.size();
    int y = s2.size();

    vector<vector<int>> c(x + 1, vector<int>(y + 1, 0));

    int lcs_length = LCS(s1, s2, x, y, c);

    cout << "DP Table: " << '\n';
    printTable(c, x, y);
    cout << '\n';

    string lcs = getLCS(s1, s2, x, y, c);

    cout << "Length of LCS: " << lcs_length << '\n';
    cout << "LCS: " << lcs << '\n';
    return 0;
}
