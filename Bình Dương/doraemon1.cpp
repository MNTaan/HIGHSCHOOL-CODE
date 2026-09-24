#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define endl "\n"
#define fi first
#define se second
#define pii pair<ll, ll>
#define file(name)                         \
    if (fopen(name ".inp", "r"))           \
    {                                      \
        freopen(name ".inp", "r", stdin);  \
        freopen(name ".out", "w", stdout); \
    }
#define fileTHHB                            \
    if (fopen("input.txt", "r"))            \
    {                                       \
        freopen("input.txt", "r", stdin);   \
        freopen("output.txt", "w", stdout); \
    }
const int maxN = 1e3 + 10;
const ll inf = -1e18 + 7;
using namespace std;
ll n, m, C;
ll dora[maxN][maxN], a[maxN][maxN];
ll dp[maxN][maxN][11], g[11];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    cin >> m >> n >> C;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            cin >> dora[i][j];

    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];

    for (int c = 0; c <= 10; c++)
        for (int i = 0; i <= m; i++)
            for (int j = 0; j <= n; j++)
                dp[i][j][c] = inf;

    for (int i = 0; i <= 10; i++)
        g[i] = inf;

    for (int j = 1; j <= n; j++)
        dp[0][j][0] = 0;

    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
        {
            dp[i][j][0] = max(dp[i][j][0], dp[i - 1][j - 1][0]);
            dp[i][j][0] = max(dp[i][j][0], dp[i - 1][j][0]);
            dp[i][j][0] = max(dp[i][j][0], dp[i - 1][j + 1][0]);
            dp[i][j][0] += a[i][j];
            if (dora[i][j])
                g[0] = max(g[0], dp[i][j][0]);
        }
    for (int c = 1; c <= 10; c++)
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
            {
                dp[i][j][c] = max(dp[i][j][c], dp[i - 1][j - 1][c]);
                dp[i][j][c] = max(dp[i][j][c], dp[i - 1][j][c]);
                dp[i][j][c] = max(dp[i][j][c], dp[i - 1][j + 1][c]);
                if (dora[i][j])
                    dp[i][j][c] = max(dp[i][j][c], g[c - 1]);
                dp[i][j][c] += a[i][j];
                if (dora[i][j])
                    g[c] = max(g[c], dp[i][j][c]);
            }
    if (C <= 10)
    {
        ll ans = inf;
        for (int j = 1; j <= n; j++)
            ans = max(ans, dp[m][j][C]);
        cout << ans;
        return 0;
    }
    ll ans1 = inf, ans2 = inf;
    for (int j = 1; j <= n; j++)
    {
        ans1 = max(ans1, dp[m][j][10]);
        ans2 = max(ans2, dp[m][j][9]);
    }
    ll D = ans1 - ans2;
    cout << ans1 + D * (C - 10);
    return 0;
}
