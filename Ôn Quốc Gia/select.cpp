#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
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
const int maxN = 2e6 + 10;
using namespace std;
int getbit(ll x, ll k)
{
    return ((x >> k) & 1);
}
int tatbit(ll x, ll k)
{
    return x & ~(1 << k);
}
ll b[2050], f[maxN];
ll n, k;
void giaima(ll mask)
{
    memset(b, 0, sizeof b);
    k = 0;
    for (int j = 1; j <= n; j++)
    {
        if (getbit(mask, j - 1) == 1)
            ++k, b[k] = j;
    }
}
ll a[2010][2010];
ll get(ll mask)
{
    ll Max = 0;
    for (int i = 1; i <= k; i++)
    {
        int j = b[i];
        int premask = tatbit(mask, j - 1);
        Max = max(Max, f[premask] + a[k][j]);
    }
    return Max;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    fill(f + 1, f + n + 1, -1e18);
    f[0] = 0;
    for (int i = 1; i <= (1 << n) - 1; i++)
    {
        giaima(i);
        f[i] = get(i);
    }
    cout << f[(1 << n) - 1];
    return 0;
}
