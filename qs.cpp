#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int low, int high)
{
    int pivot = arr[low]; int i = low + 1; int j = high;

    while(1)
    {
        while (arr[i] <= pivot)
            i++;

        while (arr[j] > pivot)
            j--;

        if (i > j)
            break;

        swap(arr[i], arr[j]);
    }

    swap(arr[low], arr[j]);

    return j;
}

void quickSort(int arr[], int low, int high)
{
    if(low < high)
    {
        int j = partition(arr, low, high);

        quickSort(arr, low, j - 1);
        quickSort(arr, j + 1, high);
    }
}

int main ()
{
    int arr[] = {10, 7, 8, 9, 1, 5, 45, 12, 65, -3, -6};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);

    cout << "Sorted Array\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << endl;
    return 0;
}
