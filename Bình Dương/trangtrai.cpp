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
const int maxN = 1e5 + 10;
using namespace std;
ll n, T;
ll a[maxN], d[maxN];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    cin >> n >> T;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a+1,a+n+1);
    while (T--)
    {
        ll d;
        cin >> d;
        ll dp[n + 1];
        memset(dp, 0, sizeof dp);
        dp[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            dp[i] = dp[i - 1] + a[i];
            if (i > 1 && a[i] - a[i - 1] <= d)
                dp[i] = dp[i - 2] + a[i];
        }
        cout << dp[n] << endl;
    }
    return 0;
}
