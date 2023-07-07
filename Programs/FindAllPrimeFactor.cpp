#include <iostream>
#include <cmath>
using namespace std;
long long int largestPrimeFactor(int n)
{
    // code here
    int mx = INT_MIN;
    while (n % 2 == 0)
    {
        // cout << 2 << " ";
        n = n / 2;
        mx = max(mx, 2);
    }
    for (int i = 3; i <= sqrt(n); i += 2)
    {
        // cout << i << " ";
        while (n % i == 0)
        {
            n /= i;
            // cout << i << " ";
            mx = max(mx, i);
        }
    }
    if (n > 2)
    {
        mx = max(mx, n);
    }
    return mx;
}
int main()
{
    cout << largestPrimeFactor(98);
}