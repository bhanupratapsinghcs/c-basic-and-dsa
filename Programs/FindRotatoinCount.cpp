#include <iostream>
using namespace std;
int FindRotationCount(int arr[], int n)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[low] <= arr[high])
        {
            return low;
        }
        int next = (mid + 1) % n, prev = (mid + n - 1) % n;
        if (arr[mid] <= arr[next] && arr[mid] <= arr[prev])
        {
            return mid;
        }
        else if (arr[mid] <= arr[high])
        {
            high = mid + 1;
        }
        else if (arr[mid] >= arr[low])
        {
            low = mid - 1;
        }
    }
    return -1;
}
int main()
{
    int arr[] = {12, 13, 14, 15, 16, 17, 18, 2, 4, 5, 6, 7, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int rotationCount = FindRotationCount(arr, n);
    cout << "Array was rotated " << rotationCount << endl;
    return 0;
}