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
const int maxN = 2e5 + 5 + 10;
const int INF = 1e18;
const int MOD = 0;
using namespace std;
ll tree[maxN], a[maxN];
void update(int i, int n, int val)
{
    for (; i <= n; i += i & -i)
        tree[i] += val;
}
ll get(int i)
{
    ll ans = 0;
    for (; i; i -= i & -i)
        ans += tree[i];
    return ans;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    ll n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = n; i >= 1; i--)
    {
        a[i] = (a[i] - a[i - 1] + m) % m;
        update(i, n, a[i] != 0);
    }
    while (q--)
    {
        int t, l, r;
        cin >> t >> l >> r;
        if (t == 1)
        {
            int v;
            cin >> v;
            update(l, n, -(a[l] != 0));
            update(r + 1, n, -(a[r + 1] != 0));
            a[l] = (a[l] + v) % m, a[r + 1] = (a[r + 1] - v + m) % m;
            update(l, n, (a[l] != 0));
            update(r + 1, n, (a[r + 1] != 0));
        }
        else if (get(r) != get(l))
            cout << "1" << endl;
        else
            cout << "0" << endl;
    }
    return 0;
}
