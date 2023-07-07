#include <bits/stdc++.h>
using namespace std;
void print(int arr[], int n);
// in this sorting first element is sorted first which is smallest of all
// void bubbleSort(int arr[], int n)
// {
//     for (int i = 0; i < n - 1; i++)
//     {
//         for (int j = i + 1; j < n; j++)
//         {
//             if (arr[j] < arr[i])
//             {
//                 int temp = arr[j];
//                 arr[j] = arr[i];
//                 arr[i] = temp;
//             }
//         }
//     }
// }
// ----------------------   OR    -----------------------
void selectionSort(int arr[], int n)
{
    int min_ind;
    for (int i = 0; i < n - 1; i++)
    {
        min_ind = i; // set min_index
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_ind]) // use min_index to comapare the next element
            {
                min_ind = j;
            }
        }
        // Swap the min_index with first element of subarr
        int temp = arr[min_ind];
        arr[min_ind] = arr[i];
        arr[i] = temp;
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
    int arr[6] = {64, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    selectionSort(arr, n);
    print(arr, n);
}