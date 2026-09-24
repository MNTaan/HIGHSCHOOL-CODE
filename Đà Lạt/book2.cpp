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
const int maxN = 5e3 + 5 + 10;
const int INF = 1e18;
const int MOD = 0;
using namespace std;
int n, k;
int A[maxN];
int dp[maxN][maxN], sum[maxN];

int calc(int l, int r)
{
    int s = sum[r] - sum[l - 1];
    return 1LL * s * s;
}

void f(int j, int l, int r, int toiuul, int toiuur)
{
    if (l > r)
        return;

    int mid = (l + r) / 2 * 1LL;
    dp[mid][j] = 1e18;
    int res = -1;

    for (int t = toiuul; t <= min(mid - 1, toiuur); ++t)
    {
        int cost = dp[t][j - 1] + calc(t + 1, mid);
        if (cost < dp[mid][j])
        {
            dp[mid][j] = cost;
            res = t;
        }
    }

    f(j, l, mid - 1, toiuul, res);
    f(j, mid + 1, r, res, toiuur);
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> A[i];
        sum[i] = sum[i - 1] + A[i];
    }

    memset(dp, 0x3f, sizeof dp);

    dp[0][0] = 0;

    for (int i = 1; i <= k; i++)
    {
        f(i, 1, n, 0, n - 1);
    }

    cout << dp[n][k] << '\n';
    return 0;
}
