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
const int maxN = 200000 + 10;
const int INF = 1e18;
const int MOD = 0;
using namespace std;
int n;
pair<pii, ll> a[maxN];
bool cmp(pair<pii, ll> a, pair<pii, ll> b)
{
    ll left = a.fi.fi * b.fi.se;
    ll right = b.fi.fi * a.fi.se;
    if (left != right)
    {
        return left > right;
    }
    return a.se < b.se;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].fi.se;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].fi.fi;
        a[i].se = i;
    }
    sort(a + 1, a + n + 1, cmp);
    cout << 1 << endl;
    cout << a[1].se;
    return 0;
}
