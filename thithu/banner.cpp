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
const int MOD = 1e9;
using namespace std;
int n, q;
string s;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    file("banner");
    cin >> n >> q;
    cin >> s;

    string target = "HSG25";
    int m = target.size();

    while (q--)
    {
        int u, v;
        cin >> u >> v;
        vector<vector<ll>> dp(v - u + 2, vector<ll>(m + 1, 0));
        dp[0][0] = 1;

        for (int i = u; i <= v; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                dp[i - u + 1][j] = dp[i - u][j];
                if (j > 0 && s[i - 1] == target[j - 1])
                {
                    dp[i - u + 1][j] = (dp[i - u + 1][j] + dp[i - u][j - 1]) % MOD;
                }
            }
        }
        cout << dp[v - u + 1][m] << endl;
    }
    return 0;
}
