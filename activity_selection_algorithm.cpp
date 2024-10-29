#include <bits/stdc++.h>
using namespace std;
int main()
{
    cout << "Enter the number of activities: ";
    int n; cin >> n;

    vector<int> s(n), f(n);

    cout << "Enter the start times: ";
    for (int i = 0; i < n; i++)
        cin >> s[i];

    cout << "Enter the finish times: ";
    for (int i = 0; i < n; i++)
        cin >> f[i];

    int j = 0;
    vector<int> a;
    a.push_back(j);

    for (int i = 1; i < n; i++)
    {
        if (s[i] >= f[j])
        {
            a.push_back(i);
            j = i;
        }
    }

    cout << "Selected activities: ";
    for (int activity : a)
        cout << activity << " ";
    cout << endl;

    return 0;
}
