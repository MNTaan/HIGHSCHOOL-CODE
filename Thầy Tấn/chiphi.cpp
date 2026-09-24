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
const int maxN = 1e4 + 10;
const int INF = 1e18;
const int MOD = 0;
using namespace std;
struct Data
{
    ll v, t, c;
};
vector<Data> adj[maxN];
ll n, m, s, t, X;
ll d[maxN], tien[maxN];
void dijkstra(ll s)
{
    fill(tien + 1, tien + n + 1, INF);
    fill(d + 1, d + n + 1, INF);
    priority_queue<pii, vector<pii>, greater<pii>> p;
    d[s] = 0;
    tien[s] = 0;
    p.push({0, s});
    while (!p.empty())
    {
        ll u = p.top().se;
        p.pop();
        for (auto x : adj[u])
        {
            ll v = x.v;
            if (d[v] > d[u] + x.t)
            {
                d[v] = d[u] + x.t;
                tien[v] = tien[u] + x.c;
                p.push({d[v], v});
            }
            else
            {
                if (d[v] == d[u] + x.t)
                    tien[v] = min(tien[v], tien[u] + x.c);
            }
        }
    }
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    file("chiphi");
    cin >> n >> m >> s >> t >> X;
    for (int i = 1; i <= n; i++)
    {
        ll u, v, t, c;
        cin >> u >> v >> c >> t;
        adj[u].pb({v, c, t});
        adj[v].pb({u, c, t});
    }
    dijkstra(s);
    if (tien[t] <= X)
        cout << tien[t];
    else
        cout << -1;
    return 0;
}
