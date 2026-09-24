#include <bits/stdc++.h>
#define ll long long
#define int long long
#define ld long double
#define pb push_back
#define endl "\n"
#define fi first
#define se second
#define FORf(i, a, b) for (ll i = a; i <= b; i++)
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
struct dt
{
    ll x, w, d;
};
dt a[maxN];
ll m, L, n;
ll res[maxN], t[maxN];
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    file("antmove");
    cin >> n >> L >> m;
    FORf(i, 1, n) cin >> a[i].x >> a[i].w >> a[i].d;
    ll limit = 0;
    FORf(i, 1, m)
    {
        cin >> t[i];
        limit = max(limit, t[i]);
    }
    ll varT = 0;
    FORf(i, 1, limit)
    {
        FORf(pos, 1, n)
        {
            if (a[pos].x != 0 && a[pos].x != L)
            {
                if (a[pos].d == 1)
                    a[pos].x++;
                else
                    a[pos].x--;
                if (a[pos].x == 0 || a[pos].x == L)
                    varT += a[pos].w;
            }
        }
        map<ll, ll> mp;
        FORf(pos, 1, n) mp[a[pos].x]++;
        FORf(pos, 1, n) if (mp[a[pos].x] > 1) a[pos].d = (a[pos].d + 1) % 2;
        res[i] = varT;
    }

    FORf(i, 1, m) cout << res[t[i]] << " ";

    return 0;
}
