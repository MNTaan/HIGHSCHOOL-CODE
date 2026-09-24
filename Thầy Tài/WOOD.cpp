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
ll h[maxN];
ll n, m;

bool check(ll mid)
{
    ll s = 0;
    for (int i = 1; i <= n; i++)
    {
        if (h[i] >= mid)
            s += (h[i] - mid);
    }
    return s >= m;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> h[i];
    ll l = 1, r = 1e18;
    ll ans = 0;
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        if (check(mid))
        {
            l = mid + 1;
            ans = mid;
        }
        else
            r = mid - 1;
    }
    cout << ans;
    return 0;
}
