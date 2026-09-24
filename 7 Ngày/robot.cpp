#include <bits/stdc++.h>
#define ll long long
#define int long long
#define ld long double
#define pb push_back
#define endl "\n"
#define fi first
#define se second
#define pii pair<ll, ll>
#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define FOD(i, a, b) for (int i = a; i >= b; --i)
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
const int maxn = 2e5 + 50;
const int cs = 5e3 + 50;
const int INF = 1e9;
const int LINF = 1e18;
using namespace std;
int n, m, q;
vector<vector<int>> a, dp1, dp2, sum1, sum2;
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    file("robot");
    cin >> n >> m >> q;
    a.resize(n + 5, vector<int>(m + 5));
    dp1.resize(n + 5, vector<int>(m + 5));
    dp2.resize(n + 5, vector<int>(m + 5));
    sum1.resize(n + 5, vector<int>(m + 5));
    sum2.resize(n + 5, vector<int>(m + 5));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];

    for (int i = 1; i <= n; i++)

        for (int j = 1; j <= m; j++)

            sum1[i][j] = max(sum1[i - 1][j], sum1[i][j - 1]) + a[i][j];

    for (int i = n; i >= 1; i--)

        for (int j = m; j >= 1; j--)

            sum2[i][j] = max(sum2[i + 1][j], sum2[i][j + 1]) + a[i][j];

    for (int i = n; i >= 1; i--)

        for (int j = 1; j <= m; j++)

            dp1[i][j] = max(max(dp1[i + 1][j], dp1[i][j - 1]), sum1[i][j] + sum2[i][j] - a[i][j]);

    for (int i = 1; i <= n; i++)

        for (int j = m; j >= 1; j--)

            dp2[i][j] = max(max(dp2[i - 1][j], dp2[i][j + 1]), sum1[i][j] + sum2[i][j] - a[i][j]);

    int tmp = dp1[n][m];
    while (q--)
    {
        int u, v;
        cin >> u >> v;
        cout << max(dp1[u + 1][v - 1], dp2[u - 1][v + 1]) << endl;
    }
    return 0;
}
