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
const int maxN = 2e5 + 10;
const int INF = 1e18;
const int MOD = 0;
using namespace std;
int n, a[maxN], p[maxN], T[4 * maxN], lazy[4 * maxN];

void down(int id)
{
    int &val = lazy[id];
    if (val == 0)
        return;
    T[id * 2] += val;
    T[id * 2 + 1] += val;
    lazy[id * 2] += val;
    lazy[id * 2 + 1] += val;
    val = 0;
}

void update(int id, int l, int r, int u, int v, int val)
{
    if (l > r)
        return;
    if (l > v || r < u)
        return;
    if (u <= l && r <= v)
    {
        T[id] += val;
        lazy[id] += val;
        return;
    }
    int m = (l + r) / 2;
    down(id);
    update(id * 2, l, m, u, v, val);
    update(id * 2 + 1, m + 1, r, u, v, val);
    T[id] = min(T[id * 2], T[id * 2 + 1]);
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int ans = 1e18, s1 = 0, s2 = 0;
    for (int i = 1; i <= n; i++)
    {
        s1 += a[i];
        update(1, 1, n, p[i], n, a[i]);
    }
    for (int i = 1; i < n; i++)

    {
        s1 -= a[i];
        s2 += a[i];
        ans = min(ans, s1);
        ans = min(ans, s2);
        update(1, 1, n, p[i], n, -a[i]);
        update(1, 1, n, 1, p[i] - 1, a[i]);
        // cout << i << ' ' << T[1] << "\n";
        ans = min(ans, T[1]);
    }
    cout << ans;
    return 0;
}
