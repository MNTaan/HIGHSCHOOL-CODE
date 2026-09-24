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
const int maxN = 3e5 + 10;
const int INF = 1e18;
const int MOD = 0;
using namespace std;
ll n, m;
vector<pii> p;
vector<ll> ke[maxN];
bool vis[maxN];
bool ck = false;
void dfs(ll s)
{
    vis[s] = true;
    if (s == n)
    {
        ck = true;
        return;
    }
    for (auto v : ke[s])
        if (!vis[v])
            dfs(v);
}
bool check(int mid)
{
    for (int i = 1; i <= n; i++)
        ke[i].clear(), vis[i] = false;
    ck = false;

    for (int i = 0; i < mid; i++)
    {
        ke[p[i].fi].pb(p[i].se);
    }
    dfs(1);
    return ck;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        p.pb({u, v});
    }
    ll l = 0, r = m, ans = INF;
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        if (check(mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    if (ans == INF)
        cout << -1;
    else
        cout << ans;
    return 0;
}
