#include <bits/stdc++.h>
using namespace std;
void print(int arr[], int n);
// in this sorting last element is sorted first
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++) // one step less for next index
    {
        for (int j = 0; j < n - i - 1; j++) // decrease inner loop and one index less
        {
            if (arr[j] > arr[j + 1]) // swap with inner loop
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
            print(arr, n);
            cout << "\n";
        }
        cout << "\n";
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
    int arr[5] = {90, 3, 2, 52, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, n);
    print(arr, n);
}