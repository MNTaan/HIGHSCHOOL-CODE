#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define endl "\n"
#define fi first
#define se second
#define pii pair<ll, ll>
#define file(name)                    \
    freopen(name ".inp", "r", stdin); \
    freopen(name ".out", "w", stdout);
#define fileTHHB                      \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout)
const int maxN = 3e5 + 10;
using namespace std;
ll n, q;
ll a[maxN], b[maxN];
struct chua
{
    ll u, l, r, i;
    chua() {}
    chua(ll u2, ll l2, ll r2, ll i2)
    {
        u = u2;
        l = l2;
        r = r2;
        i = i2;
    }
};
pii pa[maxN];
ll ans[maxN], tree[maxN];
void nhet(ll i)
{
    while (i <= maxN)
    {
        tree[i]++;
        i += i & (-i);
    }
}
ll lay(ll i)
{
    ll res = 0;
    while (i >= 1)
    {
        res += tree[i];
        i -= i & (-i);
    }
    return res;
}
vector<chua> v;
bool cmp(chua x, chua y)
{
    if (x.l != y.l)
        return x.l > y.l;
    if (x.r != y.r)
        return x.r < y.r;
    return x.u < y.u;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    if (n <= 1000 && q <= 1000)
    {
        for (int i = 1; i <= q; i++)
        {
            ll x, y, l, r;
            unordered_map<ll, ll> m;
            cin >> x >> y >> l >> r;
            for (int j = x; j <= y; j++)
                m[a[j]]++;
            for (int j = l; j <= r; j++)
                m[b[j]]++;
            ll ans = 0;
            for (auto x : m)
                if (x.se == 2)
                    ans++;
            cout << ans << endl;
        }
        return 0;
    }
    for (int i = 1; i <= n; i++)
        pa[a[i]].fi = i;
    for (int i = 1; i <= n; i++)
        pa[b[i]].se = i;
    for (int i = 1; i <= n; i++)
    {
        if (pa[i].fi > pa[i].se)
            swap(pa[i].fi, pa[i].se);
    }
    for (int i = 1; i <= n; i++)
        v.pb(chua(0, pa[i].fi, pa[i].se, -1));
    for (int i = 1; i <= q; i++)
    {
        ll x, y, l, r;
        cin >> x >> y >> l >> r;
        v.pb(chua(1, l, r, i));
    }
    sort(v.begin(), v.end(), cmp);
    for (auto x : v)
    {
        ll u = x.u;
        ll l = x.l;
        ll r = x.r;
        if (u == 0)
            nhet(r);
        else
        {
            ll i = x.i;
            ans[i] = lay(r);
        }
    }
    for (int i = 1; i <= q; i++)
        cout << ans[i] << endl;
    return 0;
}
