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
const int maxN = 200000 + 10;
const int INF = 1e18;
const int MOD = 0;
using namespace std;
ll a[5050];
ll ok[5050][5050];
ll n, ans;
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    cin >> n;
    ans = n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        ok[n + 1][i] = 1;
    }
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            ok[a[i]][a[j]] = 1;
    for (int i = 1; i < n; i++)
        ans -= ok[a[i] + 1][a[i + 1] + 1];
    cout << ans;
    return 0;
}
