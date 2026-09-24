#include <bits/stdc++.h>
#define ll long long
#define int long long
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
const int maxN = 500 + 1;
const int INF = 1e18;
const int MOD = 0;
using namespace std;
int n, m;
int d[maxN][maxN], pre[maxN][maxN], res[maxN][maxN], dp[maxN][maxN];
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    ll s;
    cin >> s;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                d[i][j] = 0;
            else
                d[i][j] = INF;
            dp[i][j] = -1;
        }

    for (int i = 1; i <= m; i++)
    {
        ll u, v, c;
        cin >> u >> v >> c;
        d[u][v] = d[v][u] = min(d[u][v], c);
        res[u][v] = res[v][u] = 1;
        dp[u][v] = dp[v][u] = d[u][v];
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            pre[i][j] = (d[i][j] == dp[i][j]);
            res[i][j] = 0;
        }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= n; k++)
            {
                if (d[i][j] == d[i][k] + d[k][j])
                    res[i][j] += pre[k][j];
            }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            pre[i][j] = res[i][j];
            res[i][j] = 0;
        }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= n; k++)
                if (d[i][j] == d[i][k] + d[k][j])
                    res[i][j] += pre[i][k];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
            cout << res[i][j] << " ";
        cout << endl;
    }
    return 0;
}
