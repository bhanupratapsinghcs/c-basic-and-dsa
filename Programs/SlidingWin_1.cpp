/**
 * @Link : https://www.hackerrank.com/challenges/deque-stl/problem
 * @Problem : 
 * Given a set of arrays of size n and an integer k, 
 * you have to find the maximum integer for each 
 * and every contiguous subarray of size  for each
 *  of the given arrays.
 */
#include <iostream>
#include <deque>
using namespace std;

void printKMax(int arr[], int n, int k)
{
    deque<int> q(k);
    int i;
    for (i = 0; i < k; i++)
    {
        while (!q.empty() && arr[i] >= arr[q.back()])
        {
            q.pop_back();
        }
        q.push_back(i);
    }
    for (; i < n; i++)
    {
        cout << arr[q.front()] << " ";
        while (!(q.empty()) && q.front() <= i - k)
        {
            q.pop_front();
        }
        while (!(q.empty()) && arr[i] >= arr[q.back()])
        {
            q.pop_back();
        }
        q.push_back(i);
    }
    cout << arr[q.front()] << endl;
}

int main()
{

    int t;
    cin >> t;
    while (t > 0)
    {
        int n, k;
        cin >> n >> k;
        int i;
        int arr[n];
        for (i = 0; i < n; i++)
            cin >> arr[i];
        printKMax(arr, n, k);
        t--;
    }
    return 0;
}
