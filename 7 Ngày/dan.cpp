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
const int cs = 5e3 + 10;

using namespace std;
ll n, k;
ll a[maxN], dp[cs][cs];
void sub2()
{
    memset(dp, 0x3f, sizeof dp);
    dp[0][0] = 0;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            ll tmp = INF;
            for (int i2 = 0; i2 < i - 1; i2++)
            {
                tmp = min(tmp, dp[i2][j - 1]);
            }
            tmp += a[i] - a[i - 1];
            dp[i][j] = min(dp[i][j], tmp);
        }
    }

    // cout << dp[4][1];
    ll res = INF;
    for (int i = 1; i <= n; i++)
        res = min(res, dp[i][k]);
    cout << res;
}
void tham()
{
    ll sum = 0;
    for (int i = 1; i + 1 <= n; i += 2)
    {
        k--;
        sum += abs(a[i] - a[i + 1]);
    }
    cout << sum;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    file("dan");
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    if (n <= 5000)
        sub2();
    else
        tham();
    return 0;
}
