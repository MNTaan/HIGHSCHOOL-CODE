#include <bits/stdc++.h>
#define ll long long
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
ll n, m, d[3][maxN], f[3][maxN];
vector<pii> ke[maxN];
void dijkstra(ll id, ll s)
{
    priority_queue<pii, vector<pii>, greater<pii>> p;
    for (int i = 1; i <= n; i++)
        d[id][i] = 1e9;
    p.push({0, s});
    f[id][s] = 1;
    d[id][s] = 0;
    while (!p.empty())
    {
        ll u = p.top().se;
        ll z = p.top().fi;
        p.pop();
        if (z > d[id][u])
            continue;
        for (auto x : ke[u])
        {
            ll v = x.fi;
            ll c = x.se;
            if (d[id][v] > d[id][u] + c)
            {
                d[id][v] = d[id][u] + c;
                p.push({d[id][v], v});
                f[id][v] = f[id][u];
            }
            else
            {
                if (d[id][v] == d[id][u] + c)
                    f[id][v] += f[id][u];
            }
            // cout<<v;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        ll u, v, c;
        cin >> u >> v >> c;
        ke[u].push_back({v, c});
        ke[v].push_back({u, c});
    }
    dijkstra(0, 1);
    dijkstra(1, n);
    vector<ll> ans;
    for (int i = 2; i < n; i++)
    {
        if (d[0][i] + d[1][i] > d[0][n])
            ans.push_back(i);
        else
        {
            if (f[0][i] * f[1][i] < f[0][n])
                ans.push_back(i);
        }
    }
    //cout<<d[1][4];
    cout << ans.size() << endl;
    for (auto u : ans)
        cout << u << endl;
    return 0;
}
