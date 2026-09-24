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
const int maxN = 2000 + 10;
const int INF = 1e18;
const int MOD = 0;
using namespace std;
ll a[maxN][maxN], f[3][maxN][maxN];
pii luu1, luu2;
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    file("bonhoa");
    ll n, m, k, r;
    cin >> n >> m >> k >> r;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            f[1][i][j] = f[1][i - 1][j] + f[1][i][j - 1] - f[1][i - 1][j - 1] + a[i][j];
    ll ans1 = -INF;
    for (int i = k; i <= n; i++)
        for (int j = k; j <= m; j++)
        {
            ll ck = f[1][i][j] - f[1][i - k][j] - f[1][i][j - k] + f[1][i - k][j - k];
            if (ck > ans1)
                ans1 = max(ans1, ck), luu1.fi = i - k + 1, luu1.se = j - k + 1;
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            f[2][i][j] = f[2][i][j - 1] + a[i][j];
    ll ans2 = -INF;
    r--;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (i - r >= 1 && i + r <= n && j - r >= 1 && j + r <= m)
            {
                ll t = 0;
                int l_left = j - 1;
                int l_right = j;
                for (int rr = i - r; rr <= i + r; rr++)
                {
                    ll ck = f[2][rr][l_right] - f[2][rr][l_left];
                    t += ck;
                    if (rr < i)
                    {
                        l_left--;
                        l_right++;
                    }
                    else if (rr >= i)
                    {
                        l_left++;
                        l_right--;
                    }
                }
                if (t > ans2)
                    ans2 = max(ans2, t), luu2 = {i, j};
            }
        }
    }
    if (ans1 == ans2)
    {
        cout << 1 << " " << luu1.fi << " " << luu1.se << " " << ans1 << endl;
        cout << 2 << " " << luu2.fi << " " << luu2.se << " " << ans2;
    }
    else if (ans1 > ans2)
        cout << 1 << " " << luu1.fi << " " << luu1.se << " " << ans1;
    else if (ans1 < ans2)
        cout << 2 << " " << luu2.fi << " " << luu2.se << " " << ans2;
    return 0;
}
