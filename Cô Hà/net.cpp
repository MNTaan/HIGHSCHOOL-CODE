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
const int maxN = 100000 + 10;
using namespace std;
ll n, m, s, t, d[maxN];
vector<pii> ke[maxN];
void dijkstra()
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, s});
    d[s] = 1e18;
    while (!pq.empty())
    {
        ll u = pq.top().se;
        pq.pop();
        for (auto x : ke[u])
        {
            ll v = x.first;
            ll c = x.se;
            ll Min = min(d[u], c);
            if (d[v] < Min)
            {
                d[v] = Min;
                pq.push({d[v], v});
            }
            // cout<<v<<" "<<d[v]<<endl;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    file("net");
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; i++)
    {
        ll u, v, c;
        cin >> u >> v >> c;
        ke[u].pb({v, c});
        ke[v].pb({u, c});
    }
    fill(d + 1, d + n + 1, -1e8);
    dijkstra();
    if (d[t] == -1e8)
        d[t] = -1;
    cout << d[t];
    return 0;
}
