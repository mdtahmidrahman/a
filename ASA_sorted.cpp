#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout << "Enter the number of activities: ";
    int n; cin >> n;

    vector<pair<int, int>> activities(n);

    cout << "Enter the start times: ";
    for (int i = 0; i < n; i++) cin >> activities[i].first;

    cout << "Enter the finish times: ";
    for (int i = 0; i < n; i++) cin >> activities[i].second;

    sort(activities.begin(), activities.end(), [](const pair<int, int>& a, const pair<int, int>& b)
    {
        return a.second < b.second;
    });

    int j = 0;
    vector<int> selected;
    selected.push_back(0);

    for (int i = 1; i < n; i++)
    {
        if (activities[i].first >= activities[j].second)
        {
            selected.push_back(i);
            j = i;
        }
    }
  
    cout << "Selected activities (0-based index after sorting): ";
    for (int index : selected)
        cout << index << " ";
    cout << endl;

    return 0;
}
