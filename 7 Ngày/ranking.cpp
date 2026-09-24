#include <bits/stdc++.h>
#define ll long long
#define int long long
#define ld long double
#define pb push_back
#define endl "\n"
#define fi first
#define se second
#define pii pair<ll, ll>
#define FORf(i, a, b) for (ll i = a; i <= b; i++)
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
const int maxN = 200000 + 10;
const int INF = 1e18;
const int MOD = 0;
using namespace std;
ll n;
ll x[maxN], y[maxN], r[maxN];
pii p[maxN], res[maxN], ans[3334][3334];
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    file("ranking");    
    cin >> n;
    FORf(i, 0, 3333) FORf(j, 0, 3333) ans[i][j] = {INF, -INF};
    FORf(i, 1, n) res[i] = {INF, -INF};
    FORf(i, 1, n) cin >> x[i] >> y[i];

    FORf(a, 1, 555)
        FORf(b, 1, 555)
    {
        FORf(i, 1, n) p[i] = {a * x[i] - b * y[i], i};
        sort(p + 1, p + n + 1, greater<pii>());

        FORf(i, 1, n) r[i] = INF;
        FORf(i, 1, n) if (r[p[i].se] == INF) r[p[i].se] = i;

        FORf(i, 1, n)
        {
            res[p[i].se].fi = min(res[p[i].se].fi, r[p[i].se]);
            res[p[i].se].se = max(res[p[i].se].se, r[p[i].se]);
        }
    }
    FORf(i, 1, n)
    {
        ans[x[i]][y[i]].fi = min(ans[x[i]][y[i]].fi, res[i].fi);
        ans[x[i]][y[i]].se = max(ans[x[i]][y[i]].fi, res[i].se);
    }
    FORf(i, 1, n) cout << ans[x[i]][y[i]].fi << " " << ans[x[i]][y[i]].se << '\n';
    return 0;
}
