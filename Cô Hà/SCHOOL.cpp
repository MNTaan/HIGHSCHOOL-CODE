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
ll n, m, s, t, d[maxN];
vector<pii> ke[maxN];
void dijkstra(ll s, ll t)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    fill(d + 1, d + n + 1, 1e18);
    d[s] = 0;
    pq.push({0, s});
    while (!pq.empty())
    {
        ll u = pq.top().se;
        pq.pop();
        for (auto x : ke[u])
        {
            ll v = x.fi;
            ll c = x.se;
            if (d[u] + c < d[v])
            {
                d[v] = d[u] + c;
                pq.push({d[v], v});
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    file("SCHOOL");
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; i++)
    {
        ll u, v, c;
        cin >> u >> v >> c;
        ke[u].pb({v, c});
    }
    dijkstra(s, t);
    if (d[t] == 1e18)
        d[t] = -1;
    cout << d[t];
    return 0;
}
