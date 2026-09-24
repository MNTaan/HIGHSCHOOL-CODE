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
const int maxN = 2e5 + 2;
const int MOD = 998244353;
ll n, d;
ll f[2208][5604][2], a[2208];
using namespace std;
template <class X, class Y>
void add(X &a, Y b)
{
    int tmp = a;
    tmp += b;
    if (tmp >= MOD)
        tmp -= MOD;
    if (tmp < 0)
        tmp += MOD;
    a = tmp;
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    cin >> n >> d;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    f[0][0][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= d; j++)
            for (int k = 0; k <= 1; k++)
            {
                add(f[i][j][1], f[i - 1][j][k]); // 1
                add(f[i][j][k], f[i - 1][j][k]); // 2
                if (j >= a[i])
                    add(f[i][j][k], f[i - 1][j - a[i]][k]); // 3
            }
    ll res = 0;
    for (int j = 0; j <= d; j++)
        add(res, f[n][j][1]);
    cout << res;
    return 0;
}
