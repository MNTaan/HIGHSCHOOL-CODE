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
const int maxN = 100 + 10;
using namespace std;
ll n;
ll s[maxN], a[maxN];
ll dp[maxN][maxN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    s[1] = a[1];
    for (int i = 2; i <= n; i++)
        s[i] = s[i - 1] + a[i];
    for (int l = 1; l <= n; l++)
    {
        for (int i = 1; i <= n - l + 1; i++)
        {
            ll j = i + l - 1;
            if (i == j)
                dp[i][j] = a[i];
            else
            {
                ll sumi = s[j] - s[i];
                ll sumj = s[j - 1] - s[i - 1];
                dp[i][j] = max(a[i] + sumi - dp[i + 1][j], a[j] + sumj - dp[i][j - 1]);
            }
        }
    }
    cout << (dp[1][n] * 2 > s[n]) << endl;
    //cout << dp[1][n] << " " << s[n];
    return 0;
}
