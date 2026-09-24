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
const int maxN = 1000 + 10;
using namespace std;
ll n, m, s, d[maxN];
vector<pii> adj[maxN];
void dijkstra()
{
    priority_queue<pii, vector<pii>, greater<pii>> p;
    p.push({0, s});
    d[s] = 1e8;
    while (!p.empty())
    {
        ll u = p.top().se;
        p.pop();
        ll z = p.top().fi;
        if (z < d[u])
            continue;
        for (auto x : adj[u])
        {
            ll v = x.fi;
            ll c = x.se;
            ll Min = min(d[u], c);

            if (d[v] < Min)
            {
                d[v] = Min;
                p.push({d[v], v});
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    file("truyentin");
    cin >> n >> m >> s;
    for (int i = 1; i <= m; i++)
    {
        ll u, v, c;
        cin >> u >> v >> c;
        adj[u].pb({v, c});
        adj[v].pb({u, c});
    }
    fill(d + 1, d + n + 1, -1e8);
    dijkstra();
    // cout<<d[s];
    for (int i = 1; i <= n; i++)
    {
        if (i != s)
            cout << d[i] << endl;
    }

    return 0;
}
