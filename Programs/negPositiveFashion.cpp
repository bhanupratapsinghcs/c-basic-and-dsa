// Rearrange array in alternating positive & negative items with O(1) extra space | Set 1
// https://www.geeksforgeeks.org/rearrange-array-alternating-positive-negative-items-o1-extra-space/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void print(vector<int> arr)
{
    for (auto &i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
}
void negPositiveFashion(vector<int> arr, int n) // time complexity O(n) -> space complexity O(n)
{
    vector<int> neg;
    vector<int> pos;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= 0)
        {
            pos.push_back(i);
        }
        else
        {
            neg.push_back(i);
        }
    }
    print(neg);
    print(pos);
    int x, y;
    x = y = 0;
    for (int i = 0; i < n; i++)
    {
        if (x < neg.size())
        {
            cout << arr[neg[x]] << " ";
            x++;
        }
        if (y < pos.size())
        {
            cout << arr[pos[y]] << " ";
            y++;
        }
    }
}
int main()
{
    vector<int> arr = {-5, 5, -2, 2, -8, 4, 7, 1, 8, 0};
    negPositiveFashion(arr, arr.size());
}