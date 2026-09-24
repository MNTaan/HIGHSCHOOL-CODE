#include <bits/stdc++.h>
#define ll unsigned long long
#define int unsigned long long
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
ll n, m;
ll a[maxN], b[maxN];
bool check(ll mid)
{
    ll sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += 1LL * (a[i] * mid) - a[i] * ((int)mid / (b[i] + 1));
    }
    return sum >= m;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i] >> b[i];
    ll l = 1, r = 1e9, ans;
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        if (check(mid))
        {
            r = mid - 1;
            ans = mid;
        }
        else
            l = mid + 1;
        // cout << l << " " << r << endl;
    }
    cout << ans;
    return 0;
}
