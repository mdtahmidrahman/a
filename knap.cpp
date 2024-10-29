#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, w, maxW;
    cout << "Max W: "; cin >> maxW;
    cout << "Items: "; cin >> n;

    int weight[n + 1], value [n + 1];
    int v[n + 1][maxW + 1];
    cout << "Weight & value: " << endl;
    for(int i = 1; i <= n; i++)
    {
        cout << "Items " << i << ": ";
        cin >> weight[i] >> value[i];
    }

    for(int i = 0; i <= n; i++)
    {
        for(int w = 0; w <= maxW; w++)
        {
            if(i == 0 || w == 0) v[i][w] = 0;
            else if(weight[i] > w) v[i][w] = v[i - 1][w];
            else v[i][w] = max(v[i - 1][w], v[i - 1][w - weight[I]] + value[i]);
        }
    }
    cout << "Maximum Profit: " << v[n][maxW] << '\n';
    cout << "Items: ";
    int i = n;
    w = maxW;
    while(i > 0 && w > 0)
    {
        if(v[i - 1][w] != v[i][w])
        {
            cout << i << " ";
            w = w - weight[i];
            i--;
        }
        else i--;
    }
    return 0;
}
