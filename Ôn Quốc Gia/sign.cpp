#include <bits/stdc++.h>
using namespace std;

const int N = 501;
int m, n, a[N][N];
long long dp[N][N];

void solve()
{
    cin >> m >> n;
    memset(dp, 0x3f, sizeof dp);
    for (int i = m; i >= 1; i--)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    for (int j = 1; j <= n; j++)
        dp[0][j] = 0;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
            dp[i][j] = min(dp[i][j], min(dp[i - 1][j], dp[i][j - 1]) + a[i][j]);
        for (int j = n; j >= 1; j--)
            dp[i][j] = min(dp[i][j], min(dp[i - 1][j], dp[i][j + 1]) + a[i][j]);
    }

    long long ans = 1e18;
    for (int i = 1; i <= n; i++)
        ans = min(ans, dp[m][i]);
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#define TASK "TASK"
    if (fopen(TASK ".inp", "r"))
    {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}