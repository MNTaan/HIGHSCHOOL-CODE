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
ll n, m, s, t;
vector<pii> ke[maxN];
bool vis[maxN];
ll ck = false;
void dfs(ll s, ll mid)
{
    vis[s] = true;
    if (s == t)
    {
        ck = true;
        return;
    }
    for (auto x : ke[s])
        if (!vis[x.fi] && mid <= x.se)
            dfs(x.fi, mid);
}
bool check(ll mid)
{
    for (int i = 1; i <= n; i++)
        vis[i] = false;
    ck = false;
    dfs(s, mid);
    return ck;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    cin >> n >> m >> s >> t;

    for (int i = 1; i <= m; i++)
    {
        ll u, v, c;
        cin >> u >> v >> c;
        ke[u].pb({v, c});
        ke[v].pb({u, c});
    }
    ll l = 1, r = 1e6, ans = 0;
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        if (check(mid))
        {
            ans = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    cout << ans;
    return 0;
}
