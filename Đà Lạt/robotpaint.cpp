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
const int maxN = 5000 + 1;
const int INF = 1e18;
const int MOD = 0;
using namespace std;
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

int n, m, d[maxN][maxN];
char a[maxN][maxN];
deque<pair<int, int>> dq;

void solve()
{
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    if (a[1][1] == 'W')
    {
        cout << -1;
        return;
    }
    d[1][1] = 1;
    dq.push_back({1, 1});
    while (dq.size())
    {
        int x = dq.front().first, y = dq.front().second;
        dq.pop_front();
        for (int i = 0; i < 4; i++)
        {
            int u = x + dx[i], v = y + dy[i];
            if (u < 1 || m < u)
                continue;
            if (v < 1 || n < v)
                continue;
            if (d[u][v])
                continue;
            if (a[u][v] == a[x][y])
            {
                d[u][v] = d[x][y];
                dq.push_front({u, v});
            }
            else if (a[u][v] != 'W')
            {
                d[u][v] = d[x][y] + 1;
                dq.push_back({u, v});
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
        {
            if (a[i][j] != 'W')
            {
                if (d[i][j] == 0)
                {
                    cout << -1;
                    return;
                }
                ans = max(ans, d[i][j]);
            }
        }
    cout << ans;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    solve();
    return 0;
}
