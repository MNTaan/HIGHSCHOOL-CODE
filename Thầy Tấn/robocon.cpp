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
const int maxN = 1e3 + 10;
const int INF = 1e18;
const int MOD = 0;
using namespace std;
int dx[5] = {-1, 0, 1, 0};
int dy[5] = {0, 1, 0, -1};
ll a[maxN][maxN], d[maxN][maxN];
bool vis[maxN][maxN];
ll n, m, x, y, u, v;

bool ck(int u, int v)
{
    if ((u < 1) || (u > m) || (v < 1) || (v > n))
        return false;
    if (a[u][v] < 0)
        return false;
    return true;
}
void bfs(int x, int y, int u, int v)
{
    queue<pii> q;
    q.push({x, y});
    vis[x][y] = true;
    d[x][y] = 1;
    while (!q.empty())
    {
        pair<int, int> cell = q.front();
        q.pop();
        int xx = cell.first;
        int yy = cell.second;
        if (xx == u && yy == v)
            break;
        for (int k = 1; k <= 4; k++)
        {
            int uu = xx + dx[k];
            int vv = yy + dy[k];
            if (ck(uu, vv) && (vis[uu][vv] == false))
            {
                d[uu][vv] = d[xx][yy] + 1;
                vis[uu][vv] = true;
                q.push({uu, vv});
            }
        }
    }
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    file("robocon");
    cin >> n >> m >> x >> y >> u >> v;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    bfs(x, y, u, v);
    if (d[u][v] == 0)
        cout << -1;
    else
        cout << d[u][v];

    return 0;
}
