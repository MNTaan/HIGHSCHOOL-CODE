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
const int maxN = 2e5 + 10;
const int INF = 1e18;
const int MOD = 0;
using namespace std;
int n, m, sz[maxN];
vector<int> adj[maxN];
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> sz[i];
        for (int j = 1; j <= sz[i]; j++)
        {
            int x;
            cin >> x;
            adj[x].pb(i);
        }
    }

    long double ans = 0;
    for (int i = 1; i <= n; i++)
    {
        long double res = 1;
        for (int j : adj[i])
            res = min(res, (long double)(sz[j] - 1) / sz[j]);
        ans = max(ans, res);
    }
    cout << fixed << setprecision(10) << ans;
    return 0;
}
