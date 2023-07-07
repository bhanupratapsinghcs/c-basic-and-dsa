#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
void SieveOfEratosthenes(int n)
{
    bool arr[n + 1];

    memset(arr, true, sizeof(arr));

    for (int i = 2; i * i <= n; i++)
    {
        if (arr[i] == true)
        {
            for (int j = i * i; j <= n; j += i)
            {
                arr[j] = false;
            }
        }
    }
    for (int i = 2; i <= n; i++)
    {
        if (arr[i] == true)
        {
            cout << i << " ";
        }
    }
    cout << endl;
}
int main()
{
    SieveOfEratosthenes(100);
}