#include <iostream>
#include <algorithm>
#include <set>
#include <map>
using namespace std;
int kthSmallest(int *arr, int l, int r, int k) // more efficient then below two method
{
    sort(arr, arr + r + 1);
    return arr[k - 1];
}
int kthSmallestusingSet(int *arr, int l, int r, int k)
{
    set<int> s(arr, arr + r + 1);
    set<int>::iterator itr = s.begin();
    advance(itr, k - 1);
    return *itr;
}
int kthSmallestUsingMap(int *arr, int l, int r, int k)
{
    map<int, int> m;
    for (int i = 0; i <= r; i++)
    {
        m[arr[i]] += 1;
    }
    int freq = 0;
    for (auto it = m.begin(); it != m.end(); it++)
    {
        freq += (it->second);
        if (freq >= k)
        {
            return it->first;
        }
    }
    return -1;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int k;
        cin >> k;
        int res = kthSmallestUsingMap(arr, 0, n - 1, k);
        cout << res << endl;
    }
}