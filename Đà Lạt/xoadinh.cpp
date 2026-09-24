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
vector<ll> ke[maxN];
ll sz[maxN];
void dfs(int u, int MAX, int &cnt, int p = -1)
{
    sz[u] = 1;
    for (auto v : ke[u])
    {
        if (v != p)
        {
            dfs(v, MAX, cnt, u);
            sz[u] += sz[v];
        }
    }
    if (sz[u] > MAX)
    {
        sz[u] = 0;
        cnt++;
    }
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    ll n, k;
    cin >> n >> k;
    for (int i = 2; i <= n; i++)
    {
        ll u;
        cin >> u;
        ke[u].pb(i);
        ke[i].pb(u);
    }
    int l = 1, h = 1e9, ans;
    while (l <= h)
    {
        int mid = (l + h) / 2;
        int cnt = 0;
        dfs(1, mid, cnt);
        // cout << mid << " " << cnt << endl;
        if (cnt <= k)
        {
            h = mid - 1;
            ans = mid;
        }
        else
            l = mid + 1;
    }
    cout << ans;
    return 0;
}
