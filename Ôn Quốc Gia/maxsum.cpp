#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define endl "\n"
#define fi first
#define se second
#define pii pair<ll, ll>
#define file(name)                    \
    freopen(name ".inp", "r", stdin); \
    freopen(name ".out", "w", stdout);
#define fileTHHB                      \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout)
const int maxN = 1e5 + 10;
using namespace std;
ll a[maxN];
vector<ll> ke[maxN];
ll d[maxN];
bool vis[maxN];
void dfs(int s)
{
    vis[s] = true;
    for (auto v : ke[s])
    {
        if (!vis[v])
        {
            vis[v] = true;
            d[v] = d[s] + a[v];
            dfs(v);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    file("maxsum");
    ll n, m;
    cin >> n;
    m = n - 1;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
    {
        ll u, v;
        cin >> u >> v;
        ke[u].pb(v);
        ke[v].pb(u);
    }
    memset(vis, false, sizeof vis);
    memset(d, 0, sizeof d);
    d[1] = a[1];
    dfs(1);
    cout << *max_element(d + 1, d + n + 1);
    return 0;
}
