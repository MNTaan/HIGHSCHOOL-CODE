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
ll n, m, X, k;
ll x[maxN], s[maxN], f[maxN], c[maxN], r[maxN], vt[maxN], summ[maxN];
pii p[maxN];

bool cmp(pii a, pii b)
{
    return a.fi < b.fi;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    cin >> n >> X >> k;
    for (int i = 1; i <= n; i++)
        cin >> p[i].fi >> p[i].se;
    sort(p + 1, p + n + 1, cmp);
    for (int i = 1; i <= n; i++)
        summ[i] = summ[i - 1] + p[i].se;
    ll res = 0;

    for (int i = 1; i <= n; i++)
        vt[i] = p[i].fi;

    ll cur_r = lower_bound(vt + 1, vt + n + 1, X) - vt;
    ll r = cur_r;
    while (r <= n && vt[r] - X <= k)
    {
        ll varT = lower_bound(vt + 1, vt + n + 1, X - k + (vt[r] - X) * 2) - vt;
        ll l = min(cur_r, varT);
        res = max(res, summ[r] - summ[l - 1]);
        r++;
    }

    ll cur_l = upper_bound(vt + 1, vt + n + 1, X) - vt - 1;
    ll l = cur_l;
    while (l >= 1 && X - vt[l] <= k)
    {
        ll varT = upper_bound(vt + 1, vt + n + 1, X + k - (X - vt[l]) * 2) - vt - 1;
        ll r = max(cur_l, varT);
        res = max(res, summ[r] - summ[l - 1]);
        l--;
    }

    cout << res;
    return 0;
}
