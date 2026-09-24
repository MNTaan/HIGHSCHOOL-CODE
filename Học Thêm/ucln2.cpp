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
void upd(int id, int l, int r, int i, int val)
{
    if (l == r)
        ST[id] = val;
    else
    {
        int mid = (l + r) / 2;
        if (i <= mid)
            upd(id * 2, l, mid, i, val);
        else
            upd(id * 2 + 1, mid + 1, r, i, val);
        ST[id] = __gcd(ST[id * 2], ST[id * 2 + 1]);
    }
}
ll get(int id, int l, int r, int u, int v)
{
    if (u > r || v < l)
        return 0;
    if (u <= l && v >= r)
        return ST[id];
    int mid = (l + r) / 2;
    return __gcd(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        upd(1, 1, n, i, x);
    }
    while (q--)
    {
        ll x;
        cin >> x;
        if (x == 1)
        {
            ll u, z;
            cin >> u >> z;
            upd(1, 1, n, u, z);
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
