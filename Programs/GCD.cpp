#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int GCD(int n, int m) // Euclidean Algorithm
{
    if (n == 0)
    {
        return m;
    }
    if (m == 0)
    {
        return n;
    }
    if (n == m)
    {
        return n;
    }
    if (n > m)
    {
        return GCD(n - m, m);
    }
    return GCD(n, m - n);
}
int GCD2(int n, int m)
{
    if (n == 0)
    {
        return m;
    }
    return GCD2(m % n, n);
}
int GCDArray(int arr[], int n)
{
    int result = arr[0];
    for (int i = 1; i < n; i++)
    {
        // cout << 'r';
        result = GCD2(arr[i], result);
        if (result == 1)
        {
            return 1;
        }
    }
    return result;
}
int main()
{
    int n = 30, m = 15;
    cin >> n;
    int arr[n];
    for (unsigned i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // cout << GCD2(n, m);
    cout << '\n'
         << GCDArray(arr, n);
}