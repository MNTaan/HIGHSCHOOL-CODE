#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
long long n, i, j, k, dp[3][320][320], a[320], zz[320];
long long sum, l, o;
long long zzz(long long z)
{
    if (zz[z] == z)
        return z;
    else
        return zz[z] = zzz(zz[z]);
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n;
    for (i = 1; i <= n; i++)
        cin >> a[i];
    for (i = 1; i <= n; i++)
        zz[i] = i;
    for (i = 1; i <= n; i++)
        for (j = i + 1; j <= n; j++)
        {
            l = sqrt(a[i] * a[j]);
            if (l * l == a[i] * a[j])
                zz[zzz(i)] = zzz(j);
        }
    for (i = 1; i <= n; i++)
        a[i] = zzz(i);
    sort(a + 1, a + n + 1);
    dp[1][0][0] = 1;
    for (i = 1; i <= n; i++)
    {
        if (a[i] != a[i - 1])
        {
            sum = 1;
            for (j = 0; j < i; j++)
            {
                for (k = 0; k <= j; k++)
                    dp[2][j][0] += dp[1][k][j - k] * (i - j);
                for (k = 0; k <= j + 1; k++)
                    dp[2][j][0] += dp[1][k][j + 1 - k] * (j + 1);
                dp[2][j][0] %= 1000000007;
            }
        }
        else
        {
            for (j = 0; j < i; j++)
                for (k = 0; k <= sum; k++)
                {
                    l = sum * 2 - k + 1;
                    o = j + 1;
                    if (k != 0)
                        dp[2][j][k] += dp[1][j][k - 1] * l;
                    dp[2][j][k] += dp[1][j + 1][k] * o;
                    if (i - l - o + 2 > 0)
                        dp[2][j][k] += dp[1][j][k] * (i - l - o + 2);
                    dp[2][j][k] %= 1000000007;
                }
            sum++;
        }
        for (j = 0; j < i; j++)
            for (k = 0; k <= i; k++)
            {
                dp[1][j][k] = dp[2][j][k];
                dp[2][j][k] = 0;
            }
    }
    cout << dp[1][0][0] << endl;
    return 0;
}
