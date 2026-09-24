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
const int maxN = 200000 + 10;
using namespace std;
ll n, m, t;
ll a[1001][1001];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
bool vis[1001][1001];
ll cnt = 0;
void dfs(int s, int t)
{
    if (a[s][t] != 0)
    {
        vis[s][t] = true;
        a[s][t] = cnt + 1;
        for (int k = 0; k < 4; k++)
        {
            int u = s + dx[k];
            int v = t + dy[k];
            if (u < 1 || u > n || v < 1 || v > m)
                continue;
            if (!vis[u][v] && a[u][v] == 1)
                dfs(u, v);
        }
    }
}
void slt()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (!vis[i][j] && a[i][j] == 1)
            {
                dfs(i, j);
                cnt++;
            }
}
ll d[1001][1001];
ll bfs(ll s, ll t)
{
    memset(vis, false, sizeof vis);
    memset(d, 0, sizeof d);
    queue<pii> q;
    int find;

    if (a[s][t] == 1)
        find = 2;
    else if (a[s][t] == 2)
        find = 1;

    q.push({s, t});
    d[s][t] = 0;
    vis[s][t] = true;

    while (!q.empty())
    {
        int u = q.front().first;
        int v = q.front().second;
        q.pop();
        for (int k = 0; k < 4; k++)
        {
            int tu = u + dx[k];
            int tv = v + dy[k];

            if (a[tu][tv] == find)
                return d[u][v];
            if (!vis[tu][tv] && tu >= 1 && tu <= n && tv >= 1 && tv <= m && a[tu][tv] == 0)
            {
                vis[tu][tv] = true;
                d[tu][tv] = d[u][v] + 1;
                q.push({tu, tv});
            }
        }
    }
    return 1e9;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    cin >> n >> m >> t;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        for (int j = 1; j <= m; j++)
        {
            a[i][j] = int(s[j - 1] - '0');
        }
    }
    slt();
    if (cnt == 1)
    {
        int s1 = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                s1 += a[i][j];
        for (int i = 1; i <= t; i++)
        {
            int s;
            cin >> s;
            if (s1 >= s)
                cout << 0 << " ";
            else
                cout << -1 << " ";
        }
    }
    else if (cnt == 2)
    {
        int size = 1e9;
        int s1 = 0, s2 = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                if (a[i][j] == 1)
                    s1++;
                else if (a[i][j] == 2)
                    s2++;
                if (a[i][j] == 1)
                {
                    ll x = bfs(i, j);
                    size = min((ll)size, x);
                }
            }
        for (int i = 1; i <= t; i++)
        {
            int s;
            cin >> s;
            if (s1 >= s || s2 >= s)
                cout << 0 << " ";
            else if (s1 + s2 >= s)
            {
                cout << size << " ";
            }
            else
                cout << -1 << " ";
        }
    }
    return 0;
}
