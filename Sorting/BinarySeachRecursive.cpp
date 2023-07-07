#include <iostream>
using namespace std;
int BinarySearch(int arr[], int low, int high, int x)
{
    if (low <= high)
    {
        //(low + high) / 2; it may exceed int value range for high value and create problem
        // <- this is to overcome overflow condition for this -^
        int mid = low + (high - low) / 2;
        if (arr[mid] == x)
        {
            return mid; // x Found, return (exit)
        }
        else if (x < arr[mid])
        {
            return BinarySearch(arr, low, mid - 1, x); // x lies before mid
        }
        else
        {
            return BinarySearch(arr, mid + 1, high, x); // x lies after mid
        }
    }
    else
        return -1;
}
int main()
{
    int A[] = {2, 4, 5, 6, 7, 9, 10, 11};
    int n = sizeof(A) / sizeof(A[0]);
    int find = 6;
    cout << BinarySearch(A, 0, n - 1, find);
}