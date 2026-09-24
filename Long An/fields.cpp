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
ll n, l, b, sum[maxN];
ll a[maxN];

ll get(ll l, ll r)
{
    ll m = (l + r) / 2;
    ll ans = 1e18;
    for (int mid = m - 1; mid <= m + 1; mid++)
    {
        if (mid < l || mid > r)
            continue;
        ans = min(ans, (ll)((mid - l + 1) * a[mid] - (sum[mid] - sum[l - 1]) + (sum[r] - sum[mid] - (r - mid) * a[mid])));
    }
    return ans;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    ll t;
    cin>>t;
    cin >> n >> l >> b;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
        sum[i] += sum[i - 1] + a[i];
    int cur = 1, ans = 0;
    for (int i = 1; i <= n; i++)
    {
        while (cur <= i && get(cur, i) > b)
            ++cur;
        ans = max(ans, i - cur + 1);
    }
    cout << ans;
    return 0;
}
