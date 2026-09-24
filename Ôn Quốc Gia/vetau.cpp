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
const int maxN = 100 + 10;
using namespace std;
ll n, k, d[maxN];
vector<pii> ke[maxN];
bool vis[maxN];
void dijkstra(ll s)
{
    priority_queue<pii, vector<pii>, greater<pii>> p;
    d[s] = 0;
    p.push({d[s], s});
    while (!p.empty())
    {
        ll u = p.top().se;
        p.pop();
        for (auto v : ke[u])
        {
            if (d[v.fi] > d[u] + v.se)
            {
                d[v.fi] = d[u] + v.se;
                p.push({d[v.fi], v.fi});
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    cin >> n >> k;
    while (k--)
    {
        ll x, u, v, c;
        cin >> x >> u >> v;
        if (x == 1)
        {
            cin >> c;
            ke[u].push_back({v, c});
            ke[v].push_back({u, c});
        }
        else
        {
            memset(vis, false, sizeof vis);
            fill(d + 1, d + n + 1, 1e18);
            dijkstra(u);
            if (d[v] == 1e18)
                d[v] = -1;
            cout << d[v]<<endl;
        }
    }
    return 0;
}
