#include <iostream>
using namespace std;
int kadanes_Algo(int *arr, int n)
{
    int max_so_for = INT_MIN, max_ending_here = 0;
    for (int i = 0; i < n; i++)
    {
        max_ending_here = max_ending_here + arr[i];
        if (max_ending_here > max_so_for)
        {
            max_so_for = max_ending_here;
        }
        if (max_ending_here < 0)
        {
            max_ending_here = 0;
        }
    }
    return max_so_for;
}
// for negative as well  as positive array
int kadanes_Algo2(int *arr, int n)
{
    int max_so_far = INT_MIN, max_ending_here = 0;
    for (int i = 0; i < n; i++)
    {
        max_ending_here = max_ending_here + arr[i];
        if (max_ending_here > max_so_far)
        {
            max_so_far = max_ending_here;
        }
        if (max_ending_here < arr[i])
        {
            max_ending_here = arr[i];
        }
    }
    return max_so_far;
}
void kadanes_Algo_subarray(int *arr, int n)
{
    int max_so_far = INT_MIN, max_ending_here = 0, start = 0, end = 0, s = 0;
    for (int i = 0; i < n; i++)
    {
        max_ending_here = max_ending_here + arr[i];
        if (max_ending_here < arr[i])
        {
            max_ending_here = arr[i];
            start = i;
        }
        if (max_ending_here > max_so_far)
        {
            max_so_far = max_ending_here;
            end = i;
        }
    }
    for (int j = start; j <= end; j++)
    {
        cout << arr[j] << " ";
    }
}
int main()
{
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << kadanes_Algo2(arr, n) << endl;
    kadanes_Algo_subarray(arr, n);
}