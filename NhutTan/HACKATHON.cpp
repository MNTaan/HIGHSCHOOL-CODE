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
struct person
{
    int a, b, c;
};
void Solve()
{
    int m, n, p;
    cin >> m >> n >> p;
    int k = m + n + p;

    vector<person> tasks(k);
    for (int i = 0; i < k; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        tasks[i] = {a, b, c};
    }
    vector<vector<vector<ll>>> dp(m + 1, vector<vector<ll>>(n + 1, vector<ll>(p + 1, INF)));
    dp[0][0][0] = 0;

    for (int i = 0; i < k; i++)
    {
        int a = tasks[i].a, b = tasks[i].b, c = tasks[i].c;
        for (int x = m; x >= 0; x--)
        {
            for (int y = n; y >= 0; y--)
            {
                for (int z = p; z >= 0; z--)
                {
                    if (x > 0)
                        dp[x][y][z] = min(dp[x][y][z], dp[x - 1][y][z] + a);
                    if (y > 0)
                        dp[x][y][z] = min(dp[x][y][z], dp[x][y - 1][z] + b);
                    if (z > 0)
                        dp[x][y][z] = min(dp[x][y][z], dp[x][y][z - 1] + c);
                }
            }
        }
    }
    cout << dp[m][n][p];
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    file("hackathon");
    Solve();
    return 0;
}
