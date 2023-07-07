#include <iostream>
using namespace std;
int BinarySearch(int arr[], int n, int x)
{
    int low = 0, high = n - 1, result = -1;
    while (low <= high)
    {
        //(low + high) / 2; it may exceed int value range for high value and create problem
        // <- this is to overcome overflow condition for this -^
        int mid = low + (high - low) / 2;
        if (arr[mid] == x)
        {
            result = mid; // x Found, return (exit)
            high = mid - 1;
        }
        else if (x < arr[mid])
        {
            high = mid - 1; // x lies before mid
        }
        else
        {
            low = mid + 1; // x lies after mid
        }
    }
    return result;
}
int main()
{
    int A[] = {2, 4, 6, 6, 6, 7, 9, 10, 11}; // Array should be sorted
    int n = sizeof(A) / sizeof(A[0]);
    int find = 6;
    cout << BinarySearch(A, n, find);
}