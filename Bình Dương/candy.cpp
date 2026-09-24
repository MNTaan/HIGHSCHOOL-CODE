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
const int maxN = 1e5 + 69;
using namespace std;
ll f[maxN][320];
ll n, k, m;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    cin >> n >> k >> m;
    f[0][0] = 1;
    for (int s = 1; s <= n; s++)
    {
        for (int i = 1; i * i <= n; i++)
        {
            if ((s - i) >= 0)
                f[s][i] = f[s - i][i];
            if ((s - 1 - (i - 1) * (k + 1)) >= 0)
                f[s][i] = (f[s][i] + f[s - 1 - (i - 1) * (k + 1)][i - 1]) % m;
        }
    }
    long long ans = 0;
    for (int i = 2; i * i <= n; i++)
        ans = (ans + f[n][i]) % m;
    cout << ans;
    return 0;
}
