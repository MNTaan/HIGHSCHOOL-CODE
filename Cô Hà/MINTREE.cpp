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
const int maxN = 1e5 + 10;
const int INF = 1e18;
const int MOD = 0;
using namespace std;
struct edge
{
    ll u, v;
    ll w;
};
ll n, m;
ll par[maxN], sz[maxN];
vector<edge> adj;
void make_set()
{
    for (int i = 1; i <= n; i++)
    {
        par[i] = i;
        sz[i] = 1;
    }
}
int find(int v)
{
    if (v == par[v])
        return v;
    return par[v] = find(par[v]);
}
bool Union(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a == b)
        return false;
    if (sz[a] < sz[b])
        swap(a, b);
    par[b] = a;
    return true;
}
bool cmp(edge a, edge b)
{
    return a.w < b.w;
}
void kruskal()
{
    vector<edge> mst;
    int d = 0;
    sort(adj.begin(), adj.end(), cmp);
    for (int i = 0; i < m; i++)
    {
        if (mst.size() == n - 1)
            break;
        edge e = adj[i];
        if (Union(e.u, e.v))
        {
            mst.push_back(e);
            d += e.w;
        }
    }
    if (mst.size() != n - 1)
        cout << "-1";
    else
        cout << d;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        edge e;
        e.u = x;
        e.v = y;
        e.w = w;
        adj.push_back(e);
    }
    make_set();
    kruskal();

    return 0;
}
