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
ll n, q, k;
ll a[maxN], BIT[maxN];
pii b[maxN];
void sub1()
{
    for (int i = 1; i <= q; i++)
    {
        ll ans = 0;
        ll tmp = 0;
        cin >> k;
        for (int j = 1; j <= n; j++)
        {
            if (a[j] <= k)
            {
                tmp++;
                ans = max(ans, tmp);
            }
            else
                tmp = 0;
        }
        cout << ans << '\n';
    }
}

ll sz[maxN], par[maxN];
void make_set()
{
    for (int i = 1; i <= n; i++)
    {
        par[i] = i;
        sz[i] = 1;
    }
}

ll find_par(ll node)
{
    if (node == par[node])
        return node;
    else
        return par[node] = find_par(par[node]);
}

void update(ll id, ll val)
{
    while (id <= n)
    {
        BIT[id] = max(BIT[id], val);
        id += id & (-id);
    }
}
int get(ll id)
{
    ll ans = -INF;
    while (id > 0)
    {
        ans = max(ans, BIT[id]);
        id -= id & (-id);
    }
    return ans;
}

void sub2()
{
    make_set();
    a[0] = a[n + 1] = INF;

    for (int i = 1; i <= n; i++)
    {
        b[i].fi = a[i];
        b[i].se = i;
    }

    sort(b + 1, b + n + 1);

    for (int i = 1; i <= n; i++)
    {
        ll pos = b[i].se;
        if (a[pos] >= a[pos - 1])
        {
            ll varT = find_par(pos - 1);
            ll uarT = find_par(pos);
            if (uarT != varT)
            {
                sz[uarT] += sz[varT];
                par[varT] = uarT;
            }
        }
        if (a[pos] >= a[pos + 1])
        {
            ll varT = find_par(pos + 1);
            ll uarT = find_par(pos);
            if (uarT != varT)
            {
                sz[uarT] += sz[varT];
                par[varT] = uarT;
            }
        }
    }

    for (int i = 1; i <= n; i++)
        BIT[i] = -INF;
    for (int i = 1; i <= n; i++)
        update(i, sz[b[i].se]);

    for (int i = 1; i <= q; i++)
    {
        cin >> k;
        int vt = upper_bound(b + 1, b + n + 1, make_pair(k, INF)) - b - 1;
        if (!vt)
            cout << 0 << '\n';
        else
            cout << get(vt) << '\n';
    }
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    if (n <= 1000 && q <= 1000)
        sub1();
    else
        sub2();
    return 0;
}
