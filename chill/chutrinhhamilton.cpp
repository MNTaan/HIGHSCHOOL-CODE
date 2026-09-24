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
const int maxN = 200000 + 10;
using namespace std;
struct node
{
    int u, v, c;
};

int n, m;
vector<pii> adj[maxN];
vector<node> save;

bool cmp(node a, node b)
{
    return a.c > b.c;
}

struct DSU
{
    int p[maxN];
    void build()
    {
        for (int i = 1; i <= n; i++)
        {
            p[i] = i;
        }
    }
    int Find(int u)
    {
        return (u == p[u]) ? u : p[u] = Find(p[u]);
    }
    bool Union(int u, int v)
    {
        u = Find(u);
        v = Find(v);
        if (u == v)
            return false;
        p[v] = u;
        return true;
    }
} dsu;

struct LCA
{
    int p[21][maxN];
    int dist[maxN];
    int h[maxN];
    void build()
    {
        memset(p, 0, sizeof p);
        memset(dist, 0, sizeof dist);
        memset(h, 0, sizeof h);
    }
    void DFS(int u)
    {
        for (auto v : adj[u])
        {
            if (v.fi != p[0][u])
            {
                p[0][v.fi] = u;
                h[v.fi] = h[u] + 1;
                dist[v.fi] = dist[u] + v.se;
                for (int i = 1; i <= 17; i++)
                {
                    p[i][v.fi] = p[i - 1][p[i - 1][v.fi]];
                }
                DFS(v.fi);
            }
        }
    }
    int Find(int u, int v)
    {
        if (h[u] < h[v])
            swap(u, v);
        int del = h[u] - h[v];
        for (int i = 0; i <= 17; i++)
        {
            if ((del >> i) & 1)
            {
                u = p[i][u];
            }
        }
        if (u == v)
            return u;
        for (int i = 17; i >= 0; i--)
        {
            if (p[i][u] != p[i][v])
            {
                u = p[i][u];
                v = p[i][v];
            }
        }
        return p[0][u];
    }

} lca;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        save.pb({u, v, c});
    }

    lca.build();
    dsu.build();

    sort(save.begin(), save.end(), cmp);
    vector<node> save2;

    for (node i : save)
    {
        if (dsu.Union(i.u, i.v))
        {
            adj[i.u].pb({i.v, i.c});
            adj[i.v].pb({i.u, i.c});
        }
        else
            save2.pb(i);
    }

    lca.DFS(1);
    int res = 1e9;
    int resso;
    for (auto i : save2)
    {
        int cc = lca.Find(i.u, i.v);
        int ans = lca.dist[i.u] + lca.dist[i.v] - 2 * lca.dist[cc] + i.c;
        int so = lca.h[i.u] + lca.h[i.v] + 1 - 2 * lca.h[cc];
        if (so == n)
        {
            if (res > ans)
            {
                res = ans;
                resso = so;
            }
        }
    }
    if (res == 1e9)
        cout << 0;
    else
    {
        cout << 1 << '\n';
        cout << res << '\n';
        cout << resso << '\n';
    }
    return 0;
}
