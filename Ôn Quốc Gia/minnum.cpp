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
int n, q;
int a[maxN];
int tree_sum[4 * maxN];

void build(int id, int l, int r)
{
    if (l == r)
    {
        tree_sum[id] = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(2 * id, l, mid);
    build(2 * id + 1, mid + 1, r);
    tree_sum[id] = min(tree_sum[2 * id], tree_sum[2 * id + 1]);
}

void update(int id, int l, int r, int x, int val)
{
    if (x < l || x > r)
        return;

    if (l == r)
    {
        tree_sum[id] = val;
        return;
    }

    int mid = l + r >> 1;
    update(2 * id, l, mid, x, val);
    update(2 * id + 1, mid + 1, r, x, val);
    tree_sum[id] = min(tree_sum[2 * id], tree_sum[2 * id + 1]);
}

int get_sum(int id, int l, int r, int u, int v)
{
    if (l > v || r < u)
        return 1e9;
    if (l >= u && r <= v)
        return tree_sum[id];

    int mid = l + r >> 1;
    int get1 = get_sum(2 * id, l, mid, u, v);
    int get2 = get_sum(2 * id + 1, mid + 1, r, u, v);
    return min(get1, get2);
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    file("minnum");
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build(1, 1, n);
    while (q--)
    {
        int k, u, v;
        cin >> k >> u >> v;
        if (k == 0)
        {
            update(1, 1, n, u, v);
        }
        else if (k == 1)
        {
            cout << get_sum(1, 1, n, u, v) << endl;
        }
    }

    return 0;
}
