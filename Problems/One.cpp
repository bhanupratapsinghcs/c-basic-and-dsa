#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, q, i, j, c, d;
    cin >> n >> q;
    vector<vector<int>> arr;
    for (i = 0; i < n; i++)
    {
        cin >> c;
        vector<int> temp;
        for (j = 0; j < c; j++)
        {
            cin >> d;
            temp.push_back(d);
        }
        arr.push_back(temp);
    }
    for (c = 0; c < q; c++)
    {
        cin >> i >> j;
        cout << arr[i][j] << endl;
    }
    return 0;
}