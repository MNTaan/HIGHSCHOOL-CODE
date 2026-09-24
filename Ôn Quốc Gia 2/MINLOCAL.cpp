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
ll m, n;
ll a[maxN];
ll ST[4 * maxN];
void build(ll id, ll l, ll r)
{
    if (l == r)
    {
        ST[id] = a[l];
        return;
    }
    ll mid = l + r >> 1;
    build(2 * id, l, mid);
    build(2 * id + 1, mid + 1, r);
    ST[id] = min(ST[2 * id], ST[2 * id + 1]);
}
void upd(ll id, ll l, ll r, ll x, ll val)
{
    if (x < l || x > r)
        return;
    if (l == r)
    {
        ST[id] = val;
        return;
    }
    ll mid = l + r >> 1;
    upd(2 * id, l, mid, x, val);
    upd(2 * id + 1, mid + 1, r, x, val);
    ST[id] = min(ST[2 * id], ST[2 * id + 1]);
}
ll get_min(ll id, ll l, ll r, ll u, ll v)
{
    if (l > v || r < u)
        return 1e9;
    if (l >= u && r <= v)
        return ST[id];
    ll mid = l + r >> 1;
    ll get1 = get_min(2 * id, l, mid, u, v);
    ll get2 = get_min(2 * id + 1, mid + 1, r, u, v);
    return min(get1, get2);
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    ll n, m;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build(1, 1, n);
    cin >> m;
    // memset(ST, 1e18, sizeof ST);
    while (m--)
    {
        ll k, u, v;
        cin >> k >> u >> v;
        if (k == 0)
        {
            upd(1, 1, n, u, a[u] - v);
            a[u]-=v;
        }
        else
        {
            cout << get_min(1, 1, n, u, v) << endl;
        }
    }
    return 0;
}
