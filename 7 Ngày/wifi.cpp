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
ll n;
ll par[maxN];
struct Data
{
    ll u, v, c;
};
Data a[maxN];
ll check(Data a, Data b)
{
    ll r = max(a.c, b.c);
    if (sqrt((a.u - b.u) * (a.u - b.u) + (a.v - b.v) * (a.v - b.v)) <= r)
        return true;
    return false;
}
vector<ll> ke[maxN];
bool vis[maxN];
void dfs(ll u)
{
    vis[u] = true;
    for (auto v : ke[u])
    {
        if (!vis[v])
            dfs(v);
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
    {
        ll u, v, c;
        cin >> a[i].u >> a[i].v >> a[i].c;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                continue;
            if (check(a[i], a[j]))
            {
                ke[i].pb(j);
                // ke[j].pb(i);
            }
        }
    }
    ll cnt = 0;
    fill(vis + 1, vis + n + 1, false);
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            cnt++;
            dfs(i);
        }
    }
    cout << cnt;
    return 0;
}
