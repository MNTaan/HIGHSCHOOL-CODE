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
const int maxN = 2000 + 10;
const int INF = 1e18;
const int MOD = 0;
using namespace std;
ll n, m, k;
ll a[maxN][maxN];
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    cin >> n >> m >> k;
    memset(a,1,sizeof a);
    for (int i = 1; i <= k; i++)
    {
        ll u, v;
        cin >> u >> v;
        a[u][v] = 0;
    }
    return 0;
}
