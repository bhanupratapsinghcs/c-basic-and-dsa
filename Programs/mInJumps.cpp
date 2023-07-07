// https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1
#include <iostream>
#include <vector>
using namespace std;
int broutForce(vector<int> arr, int n)
{
}
int count = 0;
int helper(vector<int> arr, int n)
{
    int mxR = arr[0];
    int step = arr[0];
    int jump = 1;
    if (n == 1)
    {
        return 0;
    }
    else if (mxR == 0)
    {
        return -1;
    }
    else
    {
        for (int i = 1; i < n; i++)
        {
            if (i == n - 1)
            {
                return jump;
            }
            mxR = max(mxR, i + arr[i]);
            step--;
            if (step == 0)
            {
                jump++;
                if (i >= mxR)
                {
                    return -1;
                }
                step = mxR - i;
            }
        }
    }
    cout << "Bhanu" << endl;
    return -1;
}
int minJumps(vector<int> arr, int n)
{
    vector<vector<int>> dp;
    return helper(arr, n);
}

int main()
{
    int n = 4;
    vector<int> arr = {1, 4, 5, 8, 6, 7, 2, 6, 7, 6, 8, 9, 10};
    cout << minJumps(arr, arr.size());
}