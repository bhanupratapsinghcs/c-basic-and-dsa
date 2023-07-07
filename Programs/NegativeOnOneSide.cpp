#include <iostream>
#include <vector>
using namespace std;
void negativeOnOneSide(int *arr, int n)
{
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            if (i != j)
            {
                swap(arr[i], arr[j]);
            }
            j++;
        }
    }
}
void uisngTwoPointer(int *arr, int n)
{
    int left = 0, right = n - 1;
    while (left <= right)
    {
        if (arr[left] < 0 && arr[right] < 0)
        {
            left++;
        }
        else if (arr[left] > 0 && arr[right] < 0)
        {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
            right--;
        }
        else if (arr[left] > 0 && arr[right] > 0)
        {
            right--;
        }
        else
        {
            left++;
            right--;
        }
    }
}
int main()
{
    int arr[] = {-1, 2, -3, 4, 5, 6, -7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    uisngTwoPointer(arr, n);
    for (auto &i : arr)
    {
        cout << i << " ";
    }
}