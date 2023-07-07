#include <bits/stdc++.h>
#include <string>
using namespace std;
string solve(int n, int d, int c, int m, string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'D')
        {
            if (d > 0)
            {
                d--;
                if (c == 0)
                {
                    c += m;
                }
            }
            else if (c < 0)
            {
                return "NO";
            }
            else
            {
                return "NO";
            }
        }
        else
        {
            c--;
        }
    }
    return "YES";
}
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, d, c, m;
        string s;
        cin >> n >> d >> c >> m;
        cin >> s;
        cout << solve(n, d, c, m, s) << endl;
    }
}