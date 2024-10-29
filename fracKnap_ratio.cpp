#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, maxW;
    cout << "Max W: "; cin >> maxW;
    cout << "Items: "; cin >> n;

    double weight[n], price[n], ratio[n];
    cout << "Weight & price:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Item " << i << ": ";
        cin >> weight[i] >> price[i];
        ratio[i] = price[i] / weight[i];
    }

    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(ratio[i] < ratio[j])
            {
                swap(ratio[i], ratio[j]);
                swap(weight[i], weight[j]);
                swap(price[i], price[j]);
            }
        }
    }

    double totalValue = 0.0;
    int currentWeight = 0;

    cout << "Selected items:\n";
    for(int i = 0; i < n; i++)
    {
        if(currentWeight + weight[i] <= maxW)
        {
            currentWeight += weight[i];
            totalValue += price[i];
            cout << "Item " << i << " fully taken, Weight: " << weight[i] << ", Price: " << price[i] << "\n";
        }
        else
        {
            int remainingWeight = maxW - currentWeight;
            totalValue += ratio[i] * remainingWeight;
            cout << "Item " << i << " partially taken, Weight: " << remainingWeight << ", Price: " << ratio[i] * remainingWeight << "\n";
            break;
        }
    }

    cout << "Total value in knapsack: " << totalValue << endl;
    return 0;
}
