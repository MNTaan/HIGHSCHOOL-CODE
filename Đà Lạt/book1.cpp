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
ll n, k;
ll t[maxN];
bool check(ll mid)
{
    ll phong = 0;
    ll s = 0;
    for (int i = 1; i <= n; i++)
    {
        if(s+t[i]>mid)
        {
            s=t[i];
            phong++;
        }
        else
            s+=t[i];
    }
    phong++;
    return (phong <= k);
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    cin >> n >> k;
    ll sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> t[i];
        sum += t[i];
    }
    ll l = *max_element(t + 1, t + n + 1), r = sum;
    ll ans = 1e18;
    while (l <= r)
    {
        cerr<<l<<" "<<r<<endl;
        ll mid = (l + r) / 2;
        if (check(mid))
        {
            r = mid - 1;
            ans = min(ans, mid);
        }
        else
            l = mid + 1;
    }
    cout<<l;
    return 0;
}
