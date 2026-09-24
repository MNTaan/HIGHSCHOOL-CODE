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
ll n;
ll a[maxN];
vector<ll> ke[maxN];
bool vis[maxN];
ll Max = 0, sum = 0;
void dfs(ll u)
{
    sum += a[u];
    Max = max(Max, sum);
    // cout << u << " " << sum << " " << Max << endl;
    vis[u] = true;

    for (auto v : ke[u])
    {
        if (!vis[v])
        {
            dfs(v);
            sum -= a[v];
        }
    }
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    file("SMAX");
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        vis[i] = false;
    }
    for (int i = 1; i < n; i++)
    {
        ll u, v;
        cin >> u >> v;
        ke[u].pb(v);
        ke[v].pb(u);
    }
    dfs(1);
    cout << Max;
    return 0;
}
