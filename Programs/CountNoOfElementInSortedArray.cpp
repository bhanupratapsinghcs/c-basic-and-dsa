#include <iostream>
using namespace std;
int BinarySearch(int arr[], int n, int data, bool flag)
{
    int low = 0, high = n - 1, result = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == data)
        {
            result = mid;
            if (flag)
            {
                high = mid - 1;
            }
            else
            {
                low = low + 1;
            }
        }
        else if (arr[mid] > data)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return result;
}
int main()
{
    int arr[] = {1, 2, 2, 3, 4, 5, 5, 5, 5, 6, 6, 7, 7, 8, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int firstSearch = BinarySearch(arr, n, 10, true);
    if (firstSearch == -1)
    {
        cout << "Not Found";
    }
    else
    {
        int lastSearch = BinarySearch(arr, n, 5, false);
        cout << "count of Element " << 5 << " -> " << lastSearch - firstSearch + 1 << endl;
    }
    return 0;
}