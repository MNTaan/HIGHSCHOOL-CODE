#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define fi first
#define se second
#define pii pair<ll, ll>
#define file(name)                    \
    freopen(name ".inp", "r", stdin); \
    freopen(name ".out", "w", stdout);
#define fileTHHB                      \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout)
const int maxN = 1000 + 10;
using namespace std;
ll n, m, f[maxN][maxN], a[maxN][maxN];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    for (int j = 1; j <= m; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            f[i][j] = max(f[i][j - 1], max(f[i + 1][j - 1], f[i - 1][j - 1])) + a[i][j];
        }
        f[n + 1][j] = f[1][j];
        f[0][j] = f[n][j];
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, f[i][m]);
    }
    cout << ans;
    return 0;
}
