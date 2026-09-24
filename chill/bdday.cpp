#include <bits/stdc++.h>
#define ll long long
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
const int maxN = 100 + 10;
const int INF = 1e9;
using namespace std;
vector<vector<int>> dp(maxN, vector<int>(101, INF));
int n;
int a[maxN];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    file("bdday");
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int v = 1; v <= 100; ++v)
        dp[0][v] = abs(a[0] - v);
    for (int i = 1; i < n; ++i)
    {
        for (int v = 1; v <= 100; ++v)
        {
            int min_prev = INF;
            for (int u = 1; u < v; ++u)
                min_prev = min(min_prev, dp[i - 1][u]);
            int z = min_prev + abs(a[i] - v);
            dp[i][v] = min(dp[i][v], z);
        }
    }
    int ans = INF;
    for (int v = 1; v <= 100; ++v)
    {
        ans = min(ans, dp[n - 1][v]);
    }
    cout << ans;
    return 0;
}
