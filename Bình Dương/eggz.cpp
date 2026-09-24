#include <bits/stdc++.h>
#include "egg.h"
using namespace std;

const int INF = 1e9;
int solve(int e, int n)
{
    int dp[n + 1][n + 1], opt[n + 1][n + 1];
    for (int i = 1; i <= n; i++)
        dp[i][0] = INF;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= e; j++)
        {
            if (i == 1)
            {
                dp[i][j] = opt[i][j] = 1;
                continue;
            }
            dp[i][j] = INF;
            for (int m = 1; m < i; m++)
            {
                int cost = max(dp[m - 1][j - 1], dp[i - m][j]) + 1;
                if (cost <= dp[i][j])
                {
                    dp[i][j] = cost;
                    opt[i][j] = m;
                }
            }
        }
    }

    int res = 0;
    while (n > 0)
    {
        int m = opt[n][e];
        if (drop(res + m))
        {
            n -= m;
            res += m;
        }
        else
        {
            n = m - 1;
            e--;
        }
    }
    return res;
}