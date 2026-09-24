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
ll a, k, b, m, n;
bool check(ll mid)
{
    ll tmp1 = (mid - mid / k);
    if (tmp1 >= n / a)
        tmp1 = n;
    else
        tmp1 *= a;

    ll tmp2 = (mid - mid / m);
    if (tmp2 >= n / b)
        tmp2 = n;
    else
        tmp2 *= b;
    return (tmp1 + tmp2) >= n;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    file("doncay");
    cin >> a >> k >> b >> m >> n;
    ll l = 0, r = INF;
    ll ans = INF;
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        if (check(mid))
        {
            r = mid - 1;
            ans = min(ans, mid);
        }
        else
            l = mid + 1;
    }
    cout << ans;
    return 0;
}
