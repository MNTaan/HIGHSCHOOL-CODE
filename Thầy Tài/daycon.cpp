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
ll n, m;
ll a[maxN], s[maxN];
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    cin >> n >> m;
    s[0] = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i], s[i] = s[i - 1] + a[i];
    ll dem = 0;
    for (int i = 1; i <= n; i++)
    {
        ll ub = upper_bound(s + 1, s + n + 1, s[i - 1] + m) - s - 1;
        dem += max((ll)0, ub - i + 1);
    }
    cout << dem;
    return 0;
}
