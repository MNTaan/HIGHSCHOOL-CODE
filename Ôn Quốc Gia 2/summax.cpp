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
const int maxN = 1e4 + 10;
const int INF = 1e18;
const int MOD = 0;
using namespace std;
ll n;
ll a[maxN][22], res[maxN][22];
ll dp[maxN][22];
ll getbit(ll x, ll k)
{
    return ((x >> k) & 1);
}
ll arr[] = {0, 1, 2, 4, 5, 8, 9, 10};
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i][1] >> a[i][2] >> a[i][3] >> a[i][4];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= 7; j++)
        {
            ll state = arr[j];
            ll sum = 0;
            for (int k = 0; k <= 3; k++)
            {
                if (getbit(state, k))
                    sum += a[i][k + 1];
            }
            dp[i][j] = sum;
        }
    }
    for (int i = 0; i <= 7; i++)
        res[1][i] = dp[1][i];
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j <= 7; j++)
        {
            ll state = arr[j];
            for (int k = 0; k <= 7; k++)
                if ((state & arr[k]) == 0)
                    res[i][j] = max(res[i][j], res[i - 1][k] + dp[i][j]);
        }
    }
    ll ans = -INF;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= 4; j++)
        {
            ans = max(ans, a[i][j]);
        }
    for (int i = 0; i <= 7; i++)
        ans = max(ans, res[n][i]);
    cout << ans;
    return 0;
}
