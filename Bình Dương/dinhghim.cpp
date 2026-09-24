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
const int INF = 1e9 + 7;
const int MOD = 0;
using namespace std;
int demchan(ll l, ll r)
{
    if (l % 2 != 0)
        l++;
    if (r % 2 != 0)
        r--;
    return l > r ? 0 : (r - l) / 2 + 1;
}
int demle(ll l, ll r)
{
    return l > r ? 0 : r - l + 1 - demchan(l, r);
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    int n;
    cin >> n;

    int Min1 = -INF, Min2 = -INF, Max1 = INF, Max2 = INF;
    for (int k = 0; k < n; k++)
    {
        int la = INF, ls = INF, ha = -INF, hs = -INF;
        for (int i = 0; i < 4; i++)
        {
            ll x, y;
            cin >> x >> y;
            la = min(la, x + y);
            ls = min(ls, x - y);
            ha = max(ha, x + y);
            hs = max(hs, x - y);
        }
        Min1 = max(Min1, la);
        Min2 = max(Min2, ls);
        Max1 = min(Max1, ha);
        Max2 = min(Max2, hs);
    }

    Min1++;
    Min2++;
    Max1--;
    Max2--;
    cout << 1LL * demchan(Min1, Max1) * demchan(Min2, Max2) + 1LL * demle(Min1, Max1) * demle(Min2, Max2) << endl;

    return 0;
}
