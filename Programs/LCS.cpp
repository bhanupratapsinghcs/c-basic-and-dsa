#include <iostream>
#include <string>
using namespace std;
int LCS(string str1, int n, string str2, int m)
{
    int dp[n + 1][m + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][m];
}
int main()
{
    string str1 = "AquaVitae";
    string str2 = "AruTaVae";
    int n = str1.length();
    int m = str2.length();
    cout << LCS(str1, n, str2, m);
}