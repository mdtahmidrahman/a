#include<bits/stdc++.h>
using namespace std;
void merge(int a[], int left, int mid, int right)
{
    int n1 = mid - left + 1; int n2 = right - mid;
    int L[n1], R[n2];
    for(int i = 0; i < n1; i++) L[i] = a[left + i];
    for(int j = 0; j < n2; j++) R[j] = a[mid + 1 + j];

    int i = 0; int j = 0; int k = left;
    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
        k++;
    }
    while(i < n1)
    {
        a[k] = L[i];
        i++;
        k++;
    }
    while(j < n2)
    {
        a[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int a[], int l, int r)
{
    if(l < r)
    {
        int m = l + (r - l)/2;
        mergeSort(a,l,m);
        mergeSort(a, m + 1, r);
        merge(a,l, m, r);
    }
}
int main()
{
    int a[] = {1, 3 ,2, 7, 5, 10, 4, 6, 9, 8};
    int size = sizeof(a) / sizeof(a[0]);
    mergeSort(a, 0, size - 1);
    cout << "Sorted array : ";
    for(int i = 0; i < size; i++) cout << a[i] << " ";
    return 0;
}
