#include <bits/stdc++.h>
#define int long long
#define ld long double
#define pb push_back
#define endl "\n"
#define fi first
#define se second
#define pii pair<int, int>
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
const int maxN = 2e5 + 50;
using namespace std;
int n, m, a[maxN];
vector<pii> adj[maxN];
struct node
{
    int cost, cake;
    bool operator<(const node &other) const
    {
        if (cost == other.cost)
            return cake > other.cake;
        return cost < other.cost;
    }
};
node d[maxN];
bool f[maxN];

void dijkstra(int s)
{
    memset(f, true, sizeof(f));
    for (int i = 1; i <= n; i++)
    {
        d[i].cost = 1e18;
        d[i].cake = 0;
    }
    d[s].cost = 0;
    d[s].cake = a[s];
    priority_queue<pair<node, int>, vector<pair<node, int>>, greater<pair<node, int>>> pq;
    pq.push({d[s], s});
    while (!pq.empty())
    {
        node t = pq.top().fi;
        int u = pq.top().se;
        pq.pop();
        if (u == n)
            return;
        if (!f[u])
            continue;
        f[u] = false;
        for (auto x : adj[u])
        {
            int v = x.fi;
            int c = x.se;
            if (f[v] && d[v].cost > d[u].cost + c)
            {
                d[v].cost = d[u].cost + c;
                d[v].cake = d[u].cake + a[v];
                pq.push({{d[v].cost, d[v].cake}, v});
            }
            else if (f[v] && d[v].cost == d[u].cost + c && d[v].cake < d[u].cake + a[v])
            {
                d[v].cost = d[u].cost + c;
                d[v].cake = d[u].cake + a[v];
                pq.push({{d[v].cost, d[v].cake}, v});
            }
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].pb({v, c});
        adj[v].pb({u, c});
    }
    dijkstra(1);
    if (d[n].cost != 1e18)
        cout << d[n].cost << " " << d[n].cake;
    else
        cout << "impossible";

    return 0;
}
