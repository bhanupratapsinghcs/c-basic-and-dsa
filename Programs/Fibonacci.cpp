#include <iostream>
using namespace std;
// using recursion
int fibonacci(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    else
    {
        int z = fibonacci(n - 1) + fibonacci(n - 2);
        return z;
    }
}
int dpFibonacci(int n, int cache[])
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    if (cache[n] != -1)
    {
        return cache[n];
    }
    return cache[n] = dpFibonacci(n - 1, cache) + dpFibonacci(n - 2, cache);
}
int main()
{
    cout << "Fabonacci series : ";
    int n = 20;
    int cache[n];
    for (int i = 0; i < n + 1; i++)
    {
        cache[i] = -1;
    }
    cout << fibonacci(n) << endl;

    cout << dpFibonacci(n, cache);
}