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
const int maxN = 2e6 + 10;
const int INF = 1e18;
const int MOD = 0;
using namespace std;
ll n, x, tmp, ans;
ll dp[2003][2003];
ll p[maxN], id[maxN];
vector<ll> vt[maxN];
void sang(void)
{
    ll cnt = 0;
    for (int i = 1; i <= maxN; i++)
        p[i] = i;
    for (int i = 2; i <= maxN; i++)
    {
        if (p[i] == i)
        {
            for (int j = 2 * i; j <= maxN; j += i)
            {
                p[j] = min(p[j], i);
            }
        }
    }
    for (int i = 2; i <= maxN; i++)
        if (p[i] == i)
            id[i] = ++cnt;
}
ll a[maxN];
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sang();
    for (int i = 1; i <= n; i++)
    {
        while (a[i] > 1)
        {
            tmp = p[a[i]];
            while (a[i] % tmp == 0)
                a[i] /= tmp;
            vt[i].pb(tmp);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        while (x > 1)
        {
            tmp = p[x];
            while (x % tmp == 0)
                x /= tmp;
            vt[i].pb(tmp);
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < vt[i].size(); j++)
        {
            dp[j][i] = 1;
            for (int k = 0; k < vt[i - 1].size(); k++)
            {
                if (vt[i][j] <= vt[i - 1][k])
                    break;
                else if (id[vt[i][j]] == id[vt[i - 1][k]] + 1)
                    dp[j][i] = max(dp[j][i], dp[k][i - 1] + 1);
            }
            ans = max(ans, dp[j][i]);
        }
    cout << ans;
    return 0;
}
