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
const int maxN = 1e4 + 10;
using namespace std;
ll n, m, s, t, trace[maxN];
ll num[maxN], F[maxN], dd[maxN], inPath[maxN];
vector<ll> adj[maxN], path;
void dfs(ll u)
{
    if (u == s)
        return;
    for (auto v : adj[u])
    {
        if (!trace[v])
            trace[v] = u;
        dfs(v);
    }
}
void findPath(int u, int v)
{
    path.push_back(v);
    while (v != u)
        v = trace[v], path.push_back(v);
    reverse(path.begin(), path.end());
    for (auto u : path)
        F[u] = num[u] = ++num[0], inPath[u] = 1;
}
void dfs2(int u)
{
    dd[u] = 1;
    for (auto v : adj[u])
    {
        if (inPath[v])
            F[u] = max(F[u], num[v]);
        else
        {
            if (!dd[v])
                dfs2(v);
            F[u] = max(F[u], F[v]);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; i++)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].pb(v);
    }
    dfs(s);
    findPath(s, t);
    for (auto u : path)
        dfs2(u);
    ll ans = 0, Max = 0;
    for (auto u : path)
    {
        if (u != s && u != t && Max <= num[u])
            ans++;
        Max = max(Max, F[u]);
    }
    cout << ans;
    return 0;
}
