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
const int maxN = 1e5 + 10;
const int INF = 1e18;
const int MOD = 0;
using namespace std;
ll a[maxN], s[maxN], p[maxN];
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    ll n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> s[i];
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    ll k = 1;
    ll res = INF;
    while (1)
    {
        ll ans = 0;
        for (int i = 1; i <= n; i++)
            a[i] = p[i] * k;
        for (int i = 1; i <= n; i++)
            ans += abs(s[i] - a[i]);
        if (ans > res)
            break;
        res = min(res, ans);
        k++;
    }
    cout << res;
    return 0;
}
