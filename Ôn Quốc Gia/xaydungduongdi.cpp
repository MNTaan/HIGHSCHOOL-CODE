#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define fi first
#define se second
#define pii pair<int, int>
#define file(name)                    \
    freopen(name ".inp", "r", stdin); \
    freopen(name ".out", "w", stdout);
#define fileTHHB                      \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout)
const int maxn = 10000 + 10;
const int maxm = 100000 + 10;
using namespace std;
int m, n, k, s, t, d[maxn];
vector<pii> ke[maxn];
void dijkstra(int s)
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
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    fileTHHB;
    cin >> n >> m >> k >> s >> t;
    for (int i = 1; i <= m; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        ke[u].push_back({v, c});
    }
    int Min = 1e9;
    for (int i = 1; i <= k; i++)
    {
        int x, y, q;
        cin >> x >> y >> q;
        ke[x].push_back({y, q});
        ke[y].push_back({x, q});    
        fill(d + 1, d + n + 1, 1e9);
        dijkstra(s);
        Min = min(Min, d[t]);
        ke[x].pop_back();
        ke[y].pop_back();
    }
    if (Min == 1e9)
        Min = -1;
    cout << Min;
    return 0;
}
