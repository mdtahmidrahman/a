#include<iostream>
using namespace std;

int main()
{
    int i, n, W;

    cout << "How many Items: "; cin >> n;
    cout << "Capacity: "; cin >> W;

    int v[n], w[n], t[n];

    for(int i=0;i<n;i++)
    {
        cout << "Item " << i+1 << endl;
        cout << "  Weight: "; cin >> w[i];
        cout << "  Value: "; cin >> v[i];
        t[i] = 0;
    }

    float maxr;
    int maxr_i, p=0;

    while(W>0)
    {
        maxr = -1;
        for(int i=0;i<n;i++)
        {
            if(t[i] == 0)
            {
                float temp = (float)v[i] / w[i];
                if(temp > maxr)
                {
                    maxr = temp;
                    maxr_i = i;
                }
            }
        }

        if(W >= w[maxr_i])
        {
            p = p + v[maxr_i];
            t[maxr_i] = 1;
            W = W - w[maxr_i];
            cout << "Item " << maxr_i+1 << " is taken completely." << endl;
        }
        else
        {
            p = p + (v[maxr_i] / w[maxr_i]) * W;
            cout << "Item " << maxr_i+1 << " is taken. ";
            cout << W << " kg from " << w[maxr_i] << " kg" << endl;
            W = 0;
        }
    }
    cout << "Profit = " << p;
}
