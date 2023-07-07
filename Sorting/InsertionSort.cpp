#include <bits/stdc++.h>
using namespace std;
// in this sorting key element is sorted by comparing element with sorted subaray
void insertionSort(int arr[], int n)
{
    int i, key, j; // key to Store the element to sort with sorted subarray
    for (i = 1; i < n; i++)
    {
        key = arr[i];                  // key is one step ahead of initial element
        j = i - 1;                     // subarray indexing count
        while (j >= 0 && arr[j] > key) //search subarray to find the element correct position
        {
            arr[j + 1] = arr[j]; // Shifting element ahead after comapering
            j--;
        }
        arr[j + 1] = key; // placeing key at right element
    }
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
    int arr[6] = {3, 6, 1, 6, 9, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    insertionSort(arr, n);
    print(arr, n);
}