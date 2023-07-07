#include <iostream>
#include <vector>
using namespace std;
void print2d(int **arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
bool canQueenbePlaced(int **arr, int cr, int cc, int n)
{
    int row;
    for (row = 0; row <= cr - 1; row++)
    {
        if (arr[row][cc] == 1)
        {
            return false;
        }
    }
    row = cr;
    int col = cc;
    while (row >= 0 && col >= 0)
    {
        if (arr[row--][col--] == 1)
        {
            return false;
        }
    }
    row = cr;
    col = cc;
    while (row >= 0 && col < n)
    {
        if (arr[row--][col++] == 1)
        {
            return false;
        }
    }
    return true;
}
void nQueen(int **arr, int cr, int n)
{
    if (cr == n)
    {
        print2d(arr, n);
        cout << endl;
    }
    for (int cc = 0; cc < n; cc++)
    {
        if (canQueenbePlaced(arr, cr, cc, n))
        {
            arr[cr][cc] = 1;
            nQueen(arr, cr + 1, n);
            arr[cr][cc] = 0;
        }
    }
}
int main()
{
    int n = 4;
    int **arr = new int *[n];
    for (int x = 0; x < n; x++)
    {
        arr[x] = new int[n];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = 0;
        }
    }
    nQueen(arr, 0, n);
}