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
const int MOD = 1e9 + 7;
using namespace std;
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    file("game");
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 0; j <= n; ++j)
        {
            for (int x = 0; x <= min(k, j); ++x)
            {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - x]) % MOD;
            }
        }
    }

    cout << dp[m][n] << endl;

    return 0;
}
