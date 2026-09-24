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
const int maxN = 1e6 + 10;
const int INF = 1e18;
const int MOD = 0;
using namespace std;
int n, sz[maxN];
vector<int> v[maxN];
void dfs(int u, int par)
{
    sz[u] = 1;
    for (auto v : v[u])
    {
        if (v == par)
            continue;
        dfs(v, u);
        sz[u] += sz[v];
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    cin >> n;
    for (int i = 1; i <= n - 1; i++)
    {
        ll x;
        cin >> x;
        v[i + 1].pb(x);
        v[x].pb(i + 1);
    }
    dfs(1, 0);
    sort(sz + 1, sz + n + 1);
    ll ans = 0;
    for (int i = 0; i <= n; i++)
    {
        if (sz[i])
            ans += sz[i] - 1;
        cout << ans << " ";
    }
    return 0;
}
