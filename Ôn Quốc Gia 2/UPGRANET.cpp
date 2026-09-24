#include <bits/stdc++.h>
#define ll long long
#define int long long
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
const int INF = 1e18;
const int MOD = 0;
using namespace std;
struct edge
{
    int u, v, c;
    bool f;
};
bool cmp(edge u, edge v)
{
    return (u.c > v.c);
}
const int N = 1e5 + 5, oo = 1e6 + 9;
int n, m, pa[N], Rank[N];
edge e[N];
int root, lg, times, dd[N];
pii t[N], up[N][50];
ll res;
vector<pii> a[N];
int FindSet(int u)
{
    if (u == pa[u])
        return u;
    return pa[u] = FindSet(pa[u]);
}

void check(edge &e)
{
    int u = FindSet(e.u);
    int v = FindSet(e.v);
    if (u == v)
        return;
    pa[v] = u;
    if (Rank[v] > Rank[u])
        swap(Rank[u], Rank[v]);
    if (Rank[u] == Rank[v])
        Rank[u]++;
    e.f = true;
}

void dfs(int pa, int u, int c)
{
    t[u].fi = ++times;
    dd[u] = 1;
    up[u][0] = make_pair(pa, c);
    for (int i = 1; i <= lg; i++)
    {
        int p = up[u][i - 1].fi;
        up[u][i].fi = up[p][i - 1].fi;
        up[u][i].se = min(up[u][i - 1].se, up[p][i - 1].se);
    }
    for (int i = 0; i < a[u].size(); i++)
    {
        pii f = a[u][i];
        if (f.fi != pa && !dd[f.fi])
            dfs(u, f.fi, f.se);
    }
    t[u].se = ++times;
}

bool upper(int u, int v)
{
    return (t[u].fi <= t[v].fi && t[v].se <= t[u].se);
}

int lca(int u, int v)
{
    if (upper(u, v))
        return u;
    if (upper(v, u))
        return v;
    for (int i = lg; i >= 0; i--)
        if (up[u][i].fi > 0 && !upper(up[u][i].fi, v))
            u = up[u][i].fi;
    return up[u][0].fi;
}

int get(int pa, int u)
{
    if (pa == u)
        return oo;
    int ans = oo;
    for (int i = lg; i >= 0; i--)
        if (up[u][i].fi > 0 && !upper(up[u][i].fi, pa))
        {
            ans = min(ans, up[u][i].se);
            u = up[u][i].fi;
        }
    ans = min(ans, up[u][0].se);
    return ans;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    file("UPGRANET");
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
        cin >> e[i].u >> e[i].v >> e[i].c;
    sort(e + 1, e + m + 1, cmp);
    for (int i = 1; i <= n; i++)
        pa[i] = i;
    for (int i = 1; i <= m; i++)
        check(e[i]);
    for (int i = 1; i <= m; i++)
        if (e[i].f)
        {
            int u = e[i].u, v = e[i].v, c = e[i].c;
            a[u].pb(make_pair(v, c));
            a[v].pb(make_pair(u, c));
            root = u;
        }
    for (int i = n; i > 1; i /= 2)
        lg++;
    for (int i = 0; i <= lg; i++)
        up[0][i].se = oo;
    dfs(0, root, oo);
    for (int i = 1; i <= m; i++)
        if (!e[i].f)
        {
            int u = e[i].u, v = e[i].v;
            int k = lca(u, v);
            res += (ll)(min(get(k, u), get(k, v)) - e[i].c);
        }
    cout << res;
    return 0;
}
