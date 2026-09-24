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
const int maxN = 1e4 + 10;
const int MOD = 1e9 + 7;
using namespace std;
ll n, k, dem;
ll a[maxN], x[maxN];
void ql(ll i)
{
    for (int j = 0; j <= 1; j++)
    {
        x[i] = j;
        if (i == n)
        {
            ll s = 0;
            for (int z = 1; z <= n; z++)
            {
                if (x[z] == 1)
                    s += a[z];
                else
                    s -= a[z];
            }
            if (s % k == 0)
                dem++;
            dem %= MOD;
        }
        else
            ql(i + 1);
    }
}
void sub1()
{
    ql(1);
    cout << dem % MOD;
}
ll f[maxN][1001];
void sub2()
{
    f[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= k - 1; j++)
        {
            f[i][(j + a[i]) % k] = (f[i][(j + a[i]) % k] + f[i - 1][j]) % MOD;
            f[i][((j - a[i]) + k) % k] = (f[i][((j - a[i]) + k) % k] + f[i - 1][j]) % MOD;
        }
    }
    cout << f[n][0];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    file("SEQSIGN");
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] %= k;
    }
    if (n <= 20 && k <= 10)
    {
        sub1();
    }
    else
    {
        sub2();
    }
    return 0;
}
