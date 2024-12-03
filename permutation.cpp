#include <bits/stdc++.h>
using namespace std;

void permutation(int index, string s, vector<int>& used, vector<int>& pos)
{
    if(index == s.length())
    {
        for(int i = 0; i < s.length(); i++) cout << s[pos[i]];
        cout << endl;
        return;
    }
    for(int i = 0; i < s.length(); i++)
    {
        if(used[i] == 0)
        {
            used[i] = 1;
            pos[index] = i;
            permutation(index + 1, s, used, pos);
            used[i] = 0;
        }
    }
}

int main()
{
    string s; cin >> s;

    vector<int> used(s.length(), 0);
    vector<int> pos(s.length(), 0);

    cout << "Permutations of the string \"" << s << "\" are given below:" << endl;
    permutation(0, s, used, pos);

    return 0;
}
