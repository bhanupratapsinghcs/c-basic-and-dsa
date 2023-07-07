#include <bits/stdc++.h>
using namespace std;

// O(n*log(n))
// not in-place
// stable sort

void print(int arr[], int n);
void merge(int l[], int r[], int a[], int nl, int nr)
{
    int i, j, k;
    i = j = k = 0;
    while (i < nl && j < nr)
    {
        if (l[i] <= r[j])
        {
            a[k] = l[i];
            i++;
        }
        else
        {
            a[k] = r[j];
            j++;
        }
        k++;
    }
    while (i < nl)
    {
        a[k] = l[i];
        i++;
        k++;
    }
    while (j < nr)
    {
        a[k] = r[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int n)
{
    if (n < 2)
        return;
    int mid = n / 2;
    int leftarr[mid];
    int rightarr[n - mid];
    for (int i = 0; i < mid; i++)
    {
        leftarr[i] = arr[i];
    }
    for (int j = mid; j < n; j++)
    {
        rightarr[j - mid] = arr[j];
    }
    mergeSort(leftarr, mid);
    mergeSort(rightarr, n - mid);
    merge(leftarr, rightarr, arr, mid, n - mid); // the array arr here is redueced array when we call left and right subarray
}
void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    int arr[10] = {90, 3, 2, 52, 5, 43, 2, 4, 6, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, n);
    print(arr, n);
}