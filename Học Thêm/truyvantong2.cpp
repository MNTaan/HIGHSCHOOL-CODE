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
const int maxN = 1e5 + 10;
using namespace std;
ll n, q;
ll ST[4 * maxN];
ll lazy[4 * maxN];
void down(int id, int l, int r)
{
    int mid = (l + r) / 2;
    ST[id * 2] += lazy[id] * (mid - l + 1);
    lazy[id * 2] += lazy[id];
    ST[id * 2 + 1] += lazy[id] * (r - mid);
    lazy[id * 2 + 1] += lazy[id];
    lazy[id] = 0;
}
void upd(int id, int l, int r, int u, int v, int val)
{
    if (u > r || v < l)
        return;
    if (u <= l && v >= r)
    {
        ST[id] += val * (r - l + 1);
        lazy[id] += val;
        return;
    }
    down(id, l, r);
    int mid = (l + r) / 2;
    upd(id * 2, l, mid, u, v, val);
    upd(id * 2, mid + 1, r, u, v, val);
    ST[id] = ST[id * 2] + ST[id * 2 + 1];
}
ll get(int id, int l, int r, int u, int v)
{
    if (u > r || v < l)
        return 0;
    if (u <= l && v >= r)
        return ST[id];
    down(id, u, v);
    int mid = (l + r) / 2;
    return get(id * 2, l, mid, u, v) + get(id * 2 + 1, mid + 1, r, u, v);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    ll n, q;
    cin >> n >> q;
    for (int i = 1; i <= q; i++)
    {
        ll loai;
        cin >> loai;
        if (loai == 1)
        {
            ll u, v, c;
            cin >> u >> v >> c;
            upd(1, 1, n, u, v, c);
        }
        else
        {
            ll u, v;
            cin >> u >> v;
            cout << get(1, 1, n, u, v) << endl;
        }
    }
    return 0;
}
