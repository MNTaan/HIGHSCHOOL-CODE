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
int i, j, k, m, n, p = 1, q, a[100005], y[100005], z[100005];
char x[100005];
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    file("switchsign");
    ll t;
    cin >> t;

    cin >> n >> q;
    for (; i++ < n;)
        cin >> a[i];
    for (i = 0; i++ < q;)
        cin >> x[i] >> y[i];
    for (z[100001] = 1; --i;)
    {
        if (x[i] & 2)
        {
            if (y[i] > 0)
                for (j = y[i]; !z[++j];)
                    z[j] = -p;
            else
                for (j = -y[i], p = -p; !z[j];)
                    z[j++] = p;
        }
        else
        {
            if (y[i] > 0)
                for (j = y[i], p = -p; !z[j];)
                    z[j++] = -p;
            else
                for (j = -y[i]; !z[++j];)
                    z[j] = p;
        }
    }
    for (i = 0; i++ < n;)
        cout << (z[abs(a[i])] ? abs(a[i]) * z[abs(a[i])] : a[i] * p) << ' ';
    return 0;
}
