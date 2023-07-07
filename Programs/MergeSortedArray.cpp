#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void solve(int arr1[], int arr2[], int n, int m)
{
    int i = 0, j = 0, k = n - 1;
    while (i <= k && j < m)
    {
        if (arr1[i] < arr2[j])
        {
            i++;
        }
        else
        {
            swap(arr2[j++], arr1[k--]);
        }
    }
    sort(arr1, arr1 + n);
    sort(arr2, arr2 + n);
}
void MergeWithoutExtraSpace(int arr1[], int arr2[], int n, int m)
{
    for (int i = n - 1; i >= 0; i--)
    {
        int last = arr1[m - 1];
        int j;
        for (j = m - 2; j >= 0 && arr1[j] > arr2[i]; j--)
        {
            arr1[j + 1] = arr1[j];
        }
        if (j != m - 2 && last > arr2[i])
        {
            arr1[j + 1] = arr2[i];
            arr2[i] = last;
        }
    }
}
void MergeSortedArray(int arr1[], int arr2[], int n, int m) // using merge sort approach
{
    int *res = new int[n + m];
    int i, j, k;
    i = j = k = 0;
    while (i < n && j < m)
    {
        if (arr1[i] <= arr2[j])
        {
            res[k] = arr1[i++];
        }
        else
        {
            res[k] = arr2[j++];
        }
        k++;
    }
    while (i < n)
    {
        res[k++] = arr1[i++];
    }
    while (j < m)
    {
        res[k++] = arr2[j++];
    }
    k = 0;
    print(res, n + m);
    for (int i = 0; i < n; i++)
    {
        arr1[i] = res[k++];
    }
    for (int j = 0; j < m; j++)
    {
        arr2[j] = res[k++];
    }
}
int main()
{
    int arr1[] = {1, 3, 4, 5};
    int arr2[] = {2, 4, 6, 8};
    cout << "yes";
    solve(arr1, arr2, 4, 4);
    print(arr1, 4);
    print(arr2, 4);
}