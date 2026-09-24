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
ll n, d;
pii p[maxN];
bool cmp(pii a, pii b)
{
    return a.se > b.se;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    cin >> n >> d;
    for (int i = 1; i <= n; i++)
        cin >> p[i].fi >> p[i].se;
    sort(p + 1, p + n + 1, cmp);
    for (int i = 1; i <= n; i++)
    {
        if (p[i].se >= d && p[i].fi <= d)
        {
            cout<<1;
            return 0;
        }
    }
    ll m=0,ans=0;
    while(m<d || (p[1].fi>=d && ans==1))
    {
        ans++;
        m+=p[1].se;
    }
    cout<<ans<<endl;
    return 0;
}
