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
vector<pii> ke[maxN];
ll d[maxN], n, f[maxN];
void dijsktra(ll s)
{
    priority_queue<pii, vector<pii>, greater<pii>> p;
    memset(d, 0x3f, sizeof d);
    p.push({0, s});
    d[s] = 0;
    f[s] = 1;
    while (!p.empty())
    {
        ll u = p.top().se;
        ll x = p.top().fi;
        p.pop();
        if (x > d[u])
            continue;
        for (auto x : ke[u])
        {
            ll v = x.fi;
            ll c = x.se;
            if (d[v] > d[u] + c)
            {
                d[v] = d[u] + c;
                p.push({d[v], v});
                f[v] = f[u];
            }
            else
            {
                if (d[v] == d[u] + c)
                    f[v] += f[u];
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
    ll m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        ll x, u, v, c;
        cin >> x >> u >> v >> c;
        if (x == 1)
            ke[u].push_back({v, c});
        else
        {
            ke[u].push_back({v, c});
            ke[v].push_back({u, c});
        }
    }
    dijsktra(1);
    cout << d[n] << " " << f[n];
    return 0;
}
