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
const int maxN = 1e6 + 10;
const int INF = 1e18;
const int MOD = 0;
using namespace std;
ll n, m, k;
ll x[maxN], y[maxN];
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    for (int l = 1; l <= 5; l++)
    {
        cin >> n >> m >> k;
        for (int i = 1; i <= k; i++)
            cin >> x[i] >> y[i];
        ll res = 0;
        for (int i = 1; i <= k; i++)
        {
            res ^= (x[i] - 1) ^ (y[i] - 1);
        }
        if (res == 0)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}
