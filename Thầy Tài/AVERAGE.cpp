#include <bits/stdc++.h>
#define ll long long
// #define int long long
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
const int maxN = 2e5 + 10;
const int INF = 1e18;
const int MOD = 0;
using namespace std;
int n, k;
int a[maxN];
double s[maxN];
double eps = 1e-5;
bool check(double mid)
{
    for (int i = 1; i <= n; i++)
        s[i] = 0.000;

    for (int i = 1; i <= n; i++)
        s[i] = s[i - 1] + a[i] - mid;
    double ans = 0.000;
    for (int i = k; i <= n; i++)
    {
        if (s[i] - ans >= 0)
            return true;
        ans = min(ans, s[i - k + 1]);
    }
    return false;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    double l = *min_element(a + 1, a + n + 1);
    double r = *max_element(a + 1, a + n + 1);
    double ans = 0;

    while (r - l > 1e-5)
    {
        double mid = (l + r) / 2.000;
        if (check(mid))
        {
            ans = mid;
            l = mid;
        }
        else
            r = mid;
    }
    cout << setprecision(3) << fixed << ans;
    return 0;
}
