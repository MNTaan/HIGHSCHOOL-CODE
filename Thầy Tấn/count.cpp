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
ll n, k;
vector<ll> a;
ll sum[maxN];
bool check(ll t)
{
    for (int i = t - 1; i < n; ++i)
    {
        ll cost = (ll)a[i] * t - (sum[i + 1] - sum[i - t + 1]);
        if (cost <= k)
            return true;
    }
    return false;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    cin >> n >> k;
    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    for (int i = 0; i < n; ++i)
    {
        sum[i + 1] = sum[i] + a[i];
    }
    int l = 1, r = n, cnt = 1, ans = a[0];
    while (l <= r)
    {
        int mid = l + r >> 1;
        if (check(mid))
        {
            cnt = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    for (int i = cnt - 1; i < n; ++i)
    {
        ll cost = (ll)a[i] * cnt - (sum[i + 1] - sum[i - cnt + 1]);
        if (cost <= k)
        {
            ans = a[i];
            break;
        }
    }

    cout << cnt << " " << ans << endl;
    return 0;
}
