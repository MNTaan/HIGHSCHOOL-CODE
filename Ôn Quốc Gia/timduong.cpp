#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define fi first
#define se second
#define pii pair<ll, ll>
const int maxN = 1e6;
using namespace std;
int f[333][333][333];
int a[333][333];
int dp[333][333];
int n, m, k;
int dx[] = {0, 1};
int dy[] = {1, 0};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (i == 1 && j == 1)
                dp[i][j] = a[i][j];
            else if (i == 1)
                dp[i][j] = dp[i][j - 1] + a[i][j];
            else if (j == 1)
                dp[i][j] = dp[i - 1][j] + a[i][j];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + a[i][j];
        }
    }
    f[1][1][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            for (int d = 0; d <= k; d++)
            {
                if (f[i][j][d] == 0)
                    continue;
                for (int go = 0; go <= 1; go++)
                {
                    int x = i + dx[go];
                    int y = j + dy[go];
                    if (x < 1 || x > n)
                        continue;
                    if (y < 1 || y > m)
                        continue;
                    int newd = dp[x][y] - (dp[i][j] - d + a[x][y]);
                    if (newd <= k)
                    {
                        f[x][y][newd] += f[i][j][d];
                        // f[x][y][newd] %= MOD;
                    }
                }   
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i <= k; i++)
    {
        ans += f[n][m][i];
    }
    cout << dp[n][m] << endl
         << ans;
    return 0;
}
