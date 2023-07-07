// https://www.geeksforgeeks.org/maximum-and-minimum-in-an-array/
#include <iostream>
#include <vector>
using namespace std;
struct Pair
{
    int max;
    int min;
};
Pair maxMin(int n, int *arr)
{
    Pair maxmin;
    int i;
    if (n == 1)
    {
        maxmin.min = arr[i];
        maxmin.max = arr[i];
        return maxmin;
    }
    if (arr[0] > arr[i])
    {
        maxmin.max = arr[0];
        maxmin.min = arr[1];
    }
    else
    {
        maxmin.max = arr[1];
        maxmin.min = arr[0];
    }
    for (i = 2; i < n; i++)
    {
        if (maxmin.min > arr[i])
        {
            maxmin.min = arr[i];
        }
        else if (maxmin.max < arr[i])
        {
            maxmin.max = arr[i];
        }
    }
    return maxmin;
}
int main()
{
    int arr[] = {1, 4, 1, 3, 8, 123, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    Pair res = maxMin(n, arr);
    cout << "Max value is " << res.max << ", Min value is " << res.min;
}