#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define endl "\n"
#define fi first
#define se second
#define pii pair<ll, ll>
#define file(name)                    \
    freopen(name ".inp", "r", stdin); \
    freopen(name ".out", "w", stdout);
#define fileTHHB                      \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout)
const int maxN = 200000 + 10;
using namespace std;
ll n, m;
ll a[5001][5001];
ll d[maxN], par[maxN];
bool f[maxN];
void dijkstra(ll s)
{
    memset(f, true, sizeof f);
    fill(d, d + n + 1, 2e9);
    for (int i = 1; i <= n; i++)
        par[i] = 0;
    d[s] = 0;
    while (true)
    {
        ll u = 0;
        for (int v = 1; v <= n; v++)
        {
            // cout << u << " " << d[v] << endl;
            if (f[v] && d[v] < d[u])
            {
                u = v;
            }
        }
        if (u == 0)
            break;
        f[u] = false;
        for (int v = 1; v <= n; v++)
        {
            if (a[u][v] > 0 && d[v] > d[u] + a[u][v])
            {
                d[v] = d[u] + a[u][v];
                par[v] = u;
            }
        }
    }
}
ll ans, res;
bool mark[5000][5000];
ll x[maxN], y[maxN];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    file("city");
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        ll u, v, c;
        cin >> u >> v >> c;
        a[u][v] = a[v][u] = c;
    }
    ans = 0;
    res = 0;
    dijkstra(1);
    // cout << d[2];
    memset(mark, false, sizeof mark);
    for (int u = 1; u <= n; u++)
    {
        dijkstra(u);
        for (int v = 1; v <= n; v++)
        {
            ll k = v;
            while (k != u)
            {
                mark[par[k]][k] = true;
                mark[k][par[k]] = true;
                k = par[k];
            }
        }
    }
    for (int u = 1; u <= n - 1; u++)
    {
        for (int v = u + 1; v <= n; v++)
        {
            if (mark[u][v])
            {
                res++;
                ans += a[u][v];
                x[res] = u;
                y[res] = v;
            }
        }
    }
    ll res1 = res;
    for (int i = 1; i <= res; i++)
    {
        ll k = a[x[i]][y[i]];
        a[x[i]][y[i]] = 0;
        a[y[i]][x[i]] = 0;
        dijkstra(x[i]);
        if (d[y[i]] == k)
        {
            res1--;
            ans -= k;
        }
        a[x[i]][y[i]] = k;
        a[y[i]][x[i]] = k;
    }
    cout << res1 << " " << ans;
    return 0;
}
