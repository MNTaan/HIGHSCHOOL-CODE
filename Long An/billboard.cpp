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
string s[maxN];
ll a[maxN], n, m, b[maxN];
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    file("billboard");
    cin >> n >> m;
    int ans = 1e9;
    memset(a, 0, sizeof a);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        for (int j = 0; j < m; j++)
            a[i] += (s[i][j] == 'X') << j;
    }
    for (int i = 0; i < (1 << m); i++)
    {
        for (int j = 0; j < n; j++)
            b[j] = a[j];
        int res = 0, now = i;
        for (int i = 0; i < n; i++)
        {
            res += __builtin_popcount(now);
            b[i + 1] ^= now;
            now ^= b[i] ^ (now << 1) ^ (now >> 1);
            now &= ((1 << m) - 1);
        }
        if (!now)
            ans = min(ans, res);
    }
    if (ans >= 1e9)
        cout << "Damaged billboard.\n";
    else
        cout << "You have to tap " << ans << " tiles.\n";
    return 0;
}
