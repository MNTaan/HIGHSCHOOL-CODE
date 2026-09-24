#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define fi first
#define se second
#define pii pair<ll, ll>
#define ld long double
#define file(name)                    \
    freopen(name ".inp", "r", stdin); \
    freopen(name ".out", "w", stdout);
#define fileTHHB                      \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout)
const int maxN = 1e8;
using namespace std;
// ll s1[maxN], s2[maxN];
bool check(ll a, ll b)
{
    return a < b;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    ll l, r, m;
    cin >> l >> r;
    // for (int i = l; i <= r; i++)
    //     s1[i] = s1[i - 1] + i;
    // for (int i = r; i >= l; i--)
    //     s2[i] = s2[i + 1] + i;
    ll t = l, p = r, ans = 1e9, luu = 1e9;
    while (t <= p)
    {
        ll mid = (t + p) / 2;
        ll s1 = (mid - l + 1) * (l + mid) / 2;
        ll s2 = (r - mid + 1) * (r + mid) / 2;
        if (check(s1, s2))
        {
            luu = min(luu, abs(s1 - s2 - mid));
            if (luu == abs(s1 - s2 - mid))
                ans = mid;
            t = mid + 1;
        }
        else
        {
            luu = min(luu, abs(s1 - s2 - mid));
            if (luu == abs(s1 - s2 - mid))
                ans = mid;
            p = mid - 1;
        }
    }
    cout << ans-1;
    return 0;
}
