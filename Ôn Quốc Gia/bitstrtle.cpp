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
const int maxN = 200000 + 10;
const int maxM = 1e5 + 5;
using namespace std;
ll n, f[maxM][500][2], k, a[maxM], m = 0;
char s[maxM];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    s[0] = 't';
    for (ll i = 1; i <= n; i++)
    {
        char x;
        cin >> x;
        if (s[m] == x)
        {
            a[m]++;
        }
        else
        {
            s[++m] = x;
            a[m]++;
        }
    }
    for (ll i = 0; i <= m; i++)
    {
        for (ll j = 0; j <= k; j++)
        {
            f[i][j][1] = 1e9;
            f[i][j][0] = 1e9;
        }
    }
    f[1][1][0] = 0;
    f[1][1][1] = a[1];
    for (ll i = 2; i <= m; i++)
    {
        for (ll j = 1; j <= k; j++)
        {
            f[i][j][0] = f[i - 1][j - 1][0];
            f[i][j][0] = min(f[i][j][0], f[i - 1][j][1]);
            f[i][j][0] = min(f[i][j - 1][0], f[i][j][0]);
            f[i][j][1] = f[i - 1][j - 1][1];
            f[i][j][1] = min(f[i][j][1], f[i - 1][j][0] + a[i]);
            f[i][j][1] = min(f[i][j - 1][1], f[i][j][1]);
        }
    }
    cout << min(f[m][k][0], f[m][k][1]);
    return 0;
}
