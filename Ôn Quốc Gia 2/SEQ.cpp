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
const int maxN = 1e5 + 10;
const int INF = 1e18;
const int MOD = 0;
using namespace std;
ll s[maxN];
int calc(int l, int r)
{
    if (r - l <= 1)
        return 0;
    if ((s[r] - s[l]) % 2)
        return 0;
    if (s[r] - s[l] == 0)
        return r - l - 1;
    ll half = (s[r] - s[l]) / 2;
    ll low = l, high = r;
    while (low + 1 < high)
    {
        ll mid = (low + high) / 2;
        if (s[mid] - s[l] <= half)
            low = mid;
        else
            high = mid;
    }
    if (s[low] - s[l] == half)
        return max(calc(l, low), calc(low, r)) + 1;
    return 0;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    ll T;
    cin >> T;
    while (T--)
    {
        ll n;
        cin >> n;
        for (int i = 1; i <= n; ++i)
        {
            ll x;
            cin >> x;
            s[i] = s[i - 1] + x;
        }
        cout << calc(0, n) << endl;
    }
    return 0;
}
