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
const int maxN = 5e3 + 10;
const int INF = 1e18;
const int MOD = 0;
using namespace std;
int n = 8;
int k;
int a[maxN][maxN];
bool vis[maxN][maxN];
bool check(int x, int y)
{
    if (x < 1 || x > n || y < 1 || y > n)
        return false;
    return true;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    file("quanhau");
    cin >> k;
    for (int i = 1; i <= k; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        a[u][v] = c;
        vis[u][v] = true;
    }

    int res = -INF;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            if (vis[i][j])
                continue;
            int sum = 0;
            for (int x = 1; x <= n; x++)
                sum += a[x][j];
            for (int x = 1; x <= n; x++)
                sum += a[i][x];
            int x = i, y = j;
            while (check(x, y))
            {
                sum += a[x][y];
                x--;
                y--;
            }
            x = i, y = j;
            while (check(x, y))
            {
                sum += a[x][y];
                x++;
                y++;
            }
            x = i, y = j;
            while (check(x, y))
            {
                sum += a[x][y];
                x--;
                y++;
            }
            x = i, y = j;
            while (check(x, y))
            {
                sum += a[x][y];
                x++;
                y--;
            }
            res = max(res, sum);
        }
    cout << res;
    return 0;
}
