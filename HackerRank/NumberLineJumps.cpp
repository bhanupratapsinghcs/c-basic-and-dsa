/**
 * Link : https://www.hackerrank.com/challenges/kangaroo/problem
 */
#include <bits/stdc++.h>
#include <string>
using namespace std;
string kangaroo(int x1, int v1, int x2, int v2)
{
    if ((x1 < x2 && v1 <= v2) || (x2 < x1 && v2 <= v1))
    {
        return "NO";
    }
    // if((x1%2==0 && x2%2!=0) && (v1%2==0 && v2%2!=0)){
    //     return "NO";
    // }
    if (v1 != v2 && ((x2 - x1) % (v1 - v2)) == 0)
    {
        return "YES";
    }
    return "NO";
}
int main()
{
    int x1, v1, x2, v2;
    cin >> x1 >> v1 >> x2 >> v2;
    cout << kangaroo(x1, v1, x2, v2);
    return 0;
}
