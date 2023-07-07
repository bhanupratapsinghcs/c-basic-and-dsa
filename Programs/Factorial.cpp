#include <bits/stdc++.h>
using namespace std;
// using iterative Method
long long int factorial(int n) // Must use long long for higher factorial
{
    long long int r = 1; // use long long and r  = 1
    while (n > 1)
    {
        r *= n;
        n--;
    }
    return r;
}

// using recursive Method

long long int recursiveFactorial(int n) // Must use long long for higher factorial
{
    if (n == 0)
    {
        return 1;
    }
    return n * recursiveFactorial(n - 1);
}

int main()
{
    int n = 100;
    cout << factorial(n) << endl;
    cout << recursiveFactorial(n);
}