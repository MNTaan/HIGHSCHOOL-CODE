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
const int MOD = 998244353;
using namespace std;
struct Node
{
    ll lz, ans;
} st[4 * maxN];
void Down(ll id, ll l, ll r)
{
    ll mid = l + (r - l) / 2;
    st[id * 2].lz += st[id].lz;
    st[id * 2].ans += st[id].lz * (mid - l + 1);
    st[id * 2 + 1].lz += st[id].lz;
    st[id * 2 + 1].ans += st[id].lz * (r - mid);
    st[id].lz = 0;
}

void Upd(ll id, ll l, ll r, ll u, ll v, ll val)
{
    if (r < u || v < l)
        return;
    if (u <= l && r <= v)
    {
        st[id].lz += val;
        st[id].ans += val * (r - l + 1);
        return;
    }
    Down(id, l, r);
    ll mid = l + (r - l) / 2;
    Upd(id * 2, l, mid, u, v, val);
    Upd(id * 2 + 1, mid + 1, r, u, v, val);
    st[id].ans = st[id * 2].ans + st[id * 2 + 1].ans;
}

ll Sum(ll id, ll l, ll r, ll u, ll v)
{
    if (r < u || v < l)
        return 0;
    if (u <= l && r <= v)
        return st[id].ans;
    Down(id, l, r);
    ll mid = l + (r - l) / 2;
    return Sum(id * 2, l, mid, u, v) + Sum(id * 2 + 1, mid + 1, r, u, v);
}

ll n, q, k, ai, c, l, r, x, ans;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    file("sumprod");
    cin >> n >> q >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> ai;
        Upd(1, 1, n, i, i, ai);
    }
    while (q--)
    {
        cin >> c;
        if (c == 1)
        {
            cin >> l >> r >> x;
            Upd(1, 1, n, l, r, x);
        }
        else
        {
            ans = 0;
            cin >> l >> r;
            for (int i = l; i <= r - k; i++)
                ans += (Sum(1, 1, n, i, i) % MOD * Sum(1, 1, n, i + k, r) % MOD) % MOD;
            cout << ans << '\n';
        }
    }
    return 0;
}
