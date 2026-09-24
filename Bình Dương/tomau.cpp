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
const int maxN = 50 + 10;
const int INF = 1e18;
const int MOD = 0;
using namespace std;
ll a[maxN][maxN], b[maxN][maxN];
ll n;
ll ok()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            ll res = i;
            for (int k = i; k >= 1; k--)
            {
                if (a[i][j] == a[k][j])
                    res = k;
                else
                    break;
            }
            if (i - res + 1 > n / 2)
                return j;
        }
    }
    return -1;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            char c;
            cin >> c;
            a[i][j] = (c == 'B');
        }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            b[i][j] = a[i][j];

    ll ck = ok();
    if (ck == -1)
    {
        cout << 0;
        return 0;
    }

    for (int i = 1; i <= n; i++)
    {
        ll x = a[i][ck];
        for (int j = 1; j <= n; j++)
            a[i][j] = 1 - x;
        if (ok() == -1)
        {
            cout << 1;
            return 0;
        }
        for (int j = 1; j <= n; j++)
            a[i][j] = b[i][j];
    }

    cout << 2;
    return 0;
}
