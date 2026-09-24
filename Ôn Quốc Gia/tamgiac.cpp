#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define endl "\n"
#define fi first
#define se second
#define pii pair<ll, ll>
#define pdd pair<double, double>
#define file(name)                    \
    freopen(name ".inp", "r", stdin); \
    freopen(name ".out", "w", stdout);
#define fileTHHB                      \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout)
const int maxN = 200000 + 10;
using namespace std;
pdd a[1005][5];
int n, dp[1005];
pair<double, int> dt[1005];
pdd operator-(pdd A, pdd B)
{
    return pdd(A.fi - B.fi, A.se - B.se);
}
double operator*(pdd A, pdd B)
{
    return A.fi * B.se - B.fi * A.se;
}
double tinh(pdd A, pdd B, pdd C)
{
    double s = (B - A) * (C - A);
    return abs(s) / 2.0;
}
bool check(int x, int y)
{
    if (dt[x].fi == dt[y].fi)
        return false;
    int u = dt[x].se, v = dt[y].se;
    for (int i = 1; i <= 3; i++)
    {
        double s = 0;
        for (int j = 1; j <= 3; j++)
            s += tinh(a[v][j], a[v][j + 1], a[u][i]);
        if (s != dt[y].fi)
            return false;
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i][1].fi >> a[i][1].se >> a[i][2].fi >> a[i][2].se >> a[i][3].fi >> a[i][3].se, a[i][4] = a[i][1];
    for (int i = 1; i <= n; i++)
        dt[i].fi = tinh(a[i][1], a[i][2], a[i][3]), dt[i].se = i;
    sort(dt + 1, dt + n + 1);
    int ans = 0;
    for (int i = 1; i <= n; i++)
        dp[i] = 1;
    for (int i = 1; i < n; i++)
        for (int j = i + 1; j <= n; j++)
            if (check(i, j))
                dp[j] = max(dp[j], dp[i] + 1);
    for (int i = 1; i <= n; i++)
        ans = max(ans, dp[i]);
    cout << ans;

    return 0;
}
