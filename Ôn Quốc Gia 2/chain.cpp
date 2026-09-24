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
vector<ll> adj;
bool vis[5*maxN];
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    ll T;
    cin >> T;
    adj.pb(0);
    memset(vis, false, sizeof vis);
    for (int i = 1; i <= maxN; i++)
    {
        if (vis[i] == false)
        {
            vis[i] = vis[2 * i] = vis[3 * i] = true;
            adj.pb(i);
            adj.pb(i * 2);
            adj.pb(i * 3);
        }
    }
    while (T--)
    {
        ll n;
        cin >> n;
        cout << adj[n] << endl;
    }
    return 0;
}
