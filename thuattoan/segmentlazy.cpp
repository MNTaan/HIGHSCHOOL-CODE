#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e5 + 1;
int n, m;
ll t[4 * maxn];
ll lazy[4 * maxn];

void down(int id, int l, int r)
{
    int mid = (l + r) / 2;
    t[id * 2] += lazy[id] * (mid - l + 1);
    lazy[id * 2] += lazy[id];
    t[id * 2 + 1] += lazy[id] * (r - mid);
    lazy[id * 2 + 1] += lazy[id];
    lazy[id] = 0;
}
void update(int id, int l, int r, int u, int v, ll val)
{
    if (u > r || v < l)
        return;
    if (u <= l && v >= r)
    {
        t[id] += val * (r - l + 1);
        lazy[id] += val;
        return;
    }
    down(id, l, r);

    int mid = (l + r) / 2;
    update(id * 2, l, mid, u, v, val);
    update(id * 2 + 1, mid + 1, r, u, v, val);
    t[id] = t[id * 2] + t[id * 2 + 1];
}

ll get(int id, int l, int r, int u, int v)
{
    if (u > r || v < l)
        return 0;
    if (u <= l && v >= r)
        return t[id];
    down(id, l, r);
    int mid = (l + r) / 2;
    return get(id * 2, l, mid, u, v) + get(id * 2 + 1, mid + 1, r, u, v);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n >> m;
    while (m--)
    {
        int loai;
        cin >> loai;
        if (loai == 1)
        {
            ll u, v, x;
            cin >> u >> v >> x;
            update(1, 1, n, u, v, x);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            cout << get(1, 1, n, l, r) << '\n';
        }
    }

    return 0;
}