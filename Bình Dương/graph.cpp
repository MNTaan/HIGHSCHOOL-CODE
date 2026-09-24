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
const int maxN = 2e5 + 10;
const int INF = 1e18;
const int MOD = 0;
using namespace std;
vector<pii> adj[maxN];
ll d1[maxN], Min[maxN], d2[maxN];
void dijkstra(ll s, ll d[])
{
    priority_queue<pii, vector<pii>, greater<pii>> p;
    d[s] = 0;
    p.push({0, s});
    while (!p.empty())
    {
        ll u = p.top().se;
        ll k = p.top().fi;
        p.pop();
        if (d[u] != k)
            continue;
        for (auto x : adj[u])
        {
            if (d[x.fi] > d[u] + x.se)
            {
                d[x.fi] = d[u] + x.se;
                p.push({d[x.fi], x.fi});
            }
        }
    }
}
vector<pair<pair<ll, ll>, ll>> e;
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    ll sub, T;
    cin >> sub >> T;
    while (T--)
    {
        ll n, m;
        cin >> n >> m;
        e.clear();
        for (int i = 1; i <= n; i++)
        {
            adj[i].clear();
            d1[i] = d2[i] = 1e18;
        }
        for (int i = 1; i <= m; i++)
        {
            ll u, v, c;
            cin >> u >> v >> c;
            adj[u].pb({v, c});
            adj[v].pb({u, c});
            e.pb({{u, v}, c});
        }
        dijkstra(1, d1);
        dijkstra(n, d2);
        ll res = 1e18;
        for (auto it : e)
        {
            ll u = it.fi.fi;
            ll v = it.fi.se;
            ll c = it.se;
            ll tmp1 = (d1[u] + c + d2[v]) * c;
            ll tmp2 = (d1[v] + c + d2[u]) * c;
            res = min(min(res, tmp1), tmp2);
        }
        cout << res << " ";
    }
    return 0;
}
