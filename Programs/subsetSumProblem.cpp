#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
unordered_map<string, bool> dpmap;
int solvedp(vector<int> arr, int n, int sum, vector<vector<int>> dp)
{
    if (sum == 0)
    {
        return true;
    }
    if (n < 0 || sum < 0)
    {
        return false;
    }
    string key = to_string(n) + "|" + to_string(sum);
    if (dpmap.find(key) == dpmap.end())
    {
        bool include = solvedp(arr, n - 1, sum - arr[n - 1], dp);
        bool exclude = solvedp(arr, n - 1, sum, dp);
        dpmap[key] = include || exclude;
    }

    return dpmap[key];
}
bool subsetSum(int arr[], int n, int sum)
{
    // `T[i][j]` stores true if subset with sum `j` can be attained
    // using items up to first `i` items
    bool T[n + 1][sum + 1];

    // if 0 items in the list and the sum is non-zero
    for (int j = 1; j <= sum; j++)
    {
        T[0][j] = false;
    }

    // if the sum is zero
    for (int i = 0; i <= n; i++)
    {
        T[i][0] = true;
    }

    // do for i'th item
    for (int i = 1; i <= n; i++)
    {
        // consider all sum from 1 to sum
        for (int j = 1; j <= sum; j++)
        {
            // don't include the i'th element if `j-arr[i-1]` is negative
            if (arr[i - 1] > j)
            {
                cout << std::boolalpha << T[i - 1][j] << " 1.->" << arr[i - 1];
                T[i][j] = T[i - 1][j];
            }
            else
            {
                cout << std::boolalpha << (T[i - 1][j] || T[i - 1][j - arr[i - 1]]) << " 2.->" << arr[i - 1];
                // find the subset with sum `j` by excluding or including the i'th item
                T[i][j] = T[i - 1][j] || T[i - 1][j - arr[i - 1]];
            }
        }
        cout << endl;
    }

    // return maximum value
    return T[n][sum];
}
int solve(vector<int> arr, int n, int sum, vector<vector<int>> dp)
{
    if (sum == 0)
    {
        return true;
    }
    if (n < 0 || sum < 0)
    {
        return false;
    }
    bool include = solve(arr, n - 1, sum - arr[n - 1], dp);
    bool exclude = solve(arr, n - 1, sum, dp);
    return include || exclude;
}
int main()
{
    vector<int> arr{3, 34, 4, 12, 5, 2};
    int sum = 9;
    vector<vector<int>> dp;
    cout << solvedp(arr, arr.size() - 1, sum, dp);
}