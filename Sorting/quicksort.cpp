#include <bits/stdc++.h>
using namespace std;
// O(nlog(n)) in avg O(n2n) in worst case
// in-place
//
void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int partition(int *a, int s, int e)
{
    int pivot = a[e]; //pivot is taken the end element
    int partitionIndex = s;
    for (int i = s; i < e; i++)
    {
        if (a[i] <= pivot)
        {
            swap(a[i], a[partitionIndex]);
            partitionIndex++;
        }
    }
    swap(a[partitionIndex], a[e]);
    // cout << partitionIndex << " " << e << endl;
    return partitionIndex;
}
void quicksort(int *arr, int s, int e)
{
    if (s < e)
    {
        int partitionIndex = partition(arr, s, e);
        // cout << s << " " << partitionIndex << " f\n";
        quicksort(arr, s, partitionIndex - 1);
        // cout << "l\n";
        quicksort(arr, partitionIndex + 1, e);
    }
}
int main()
{
    int arr[] = {4, 2, 1, 6, 8, 5, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    quicksort(arr, 0, n - 1);
    print(arr, n);
}