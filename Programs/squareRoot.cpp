#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
float squareRoot(int n) // using binary search not optimise
{
    float low = 0.0;
    float high = (float)n + 1;
    while ((high - low) > 0.00001)
    {
        float mid = low + (high - low) / 2;
        if (mid * mid < n)
        {
            low = mid;
        }
        else
        {
            high = mid;
        }
    }
    return low;
}
int main()
{
    int n = 17;
    cout << ceil(squareRoot(n));
}