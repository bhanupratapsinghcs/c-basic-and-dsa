// https://practice.geeksforgeeks.org/problems/minimize-the-heights3351/1
#include <iostream>
#include <algorithm>
#include <vector>
#define pii pair<int, int>
using namespace std;
int MintheMaxdiff(int *arr, int n, int k)
{
    // first approach using sliding window
    // if (n == 1)
    // {
    //     return 0;
    // }
    // vector<pair<int, int>> v;
    // vector<int> window(n, 0);
    // for (int i = 0; i < n; i++)
    // {
    //     if (arr[i] - k >= 0)
    //     {
    //         v.push_back(make_pair(arr[i] - k, i));
    //     }
    //     v.push_back(make_pair(arr[i] + k, i));
    // }

    // sort(v.begin(), v.end());
    // int ele = 0;
    // int left = 0;
    // int right = 0;

    // // initializing the window for first time
    // while (ele < n && right < v.size())
    // {
    //     if (window[v[right].second == 0])
    //     {
    //         ele++;
    //     }
    //     window[v[right].second]++;
    //     right++;
    // }

    // int ans = v[right - 1].first - v[left].first;
    // while (right < v.size())
    // {
    //     if (window[v[left].second] == 1)
    //     {
    //         ele--;
    //     }
    //     window[v[left].second]--;
    //     left++;
    //     while (ele < n && right < v.size())
    //     {
    //         if (window[v[right].second] == 0)
    //         {
    //             ele++;
    //         }
    //         window[v[right].second]++;
    //         right++;
    //     }
    //     if (ele == n)
    //         ans = min(ans, v[right - 1].first - v[left].first);
    //     else
    //         break;
    // }
    // cout << ans << endl;
    // return ans;

    // second approach is min the running currenttly

    sort(arr, arr + n);
    int ans = arr[n - 1] - arr[0];
    int smallest = arr[0] + k;
    int largest = arr[n - 1] - k;
    int mn, mx;
    for (int i = 0; i < n - 1; i++)
    {
        cout << arr[i + 1] << " ";
        mn = min(smallest, arr[i + 1] - k);
        cout << mn << " ";
        mx = max(largest, arr[i] + k);
        cout << mx << " ";
        if (mn < 0)
        {
            continue;
        }
        ans = min(ans, mx - mn);
        cout << ans << endl;
    }
    cout << ans << endl;
}
int main()
{
    int k = 5;
    int arr[] = {8, 1, 5, 4, 7, 5, 7, 9, 4, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    MintheMaxdiff(arr, n, k);
}