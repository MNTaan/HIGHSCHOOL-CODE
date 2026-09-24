#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pii pair<int, int>
const int maxN = 1e6;
using namespace std;
ll n, m, k, d[maxN];
vector<ll> ke[maxN];
void dijkstra(ll s, ll t)
{
    priority_queue<pii, vector<pii>, greater<pii>> p;
    fill(d + 1, d + n + 1, 1e9);
    d[s] = 0;
    p.push({0, s});
    while (!p.empty())
    {
        ll u = p.top().se;
        ll dd = p.top().fi;
        p.pop();
        if (dd > d[u])
            continue;
        for (auto z : ke[u])
        {
            ll v = z;
            if (d[v] > d[u] + 1)
            {
                d[v] = d[u] + 1;
                p.push({d[v], v});
            }
        }
    }
    d[s] = 0;
}
signed main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("thi.inp", "r", stdin);
    freopen("thi.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
    {
        ll u, v;
        cin >> u >> v;
        ke[u].pb(v);
        ke[v].pb(u);
    }
    ll s = 1;
    dijkstra(s, n);
    if (d[s] == 0)
        cout << "YES";
    return 0;
}
