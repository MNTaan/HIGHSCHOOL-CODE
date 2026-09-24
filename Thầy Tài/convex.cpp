#include <bits/stdc++.h>
#define ll long long
#define int long long
#define ld long double
#define pb push_back
#define endl "\n"
#define x first
#define y second
#define pii pair<ll, ll>
#define pdd pair<ld, ld>

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
pdd a[maxN];
ll n;
bool ccw(pdd A, pdd B, pdd C)
{
    return 1LL * (B.x - A.x) * (C.y - A.y) - 1LL * (C.x - A.x) * (B.y - A.y) > 0;
}
bool cmp(pdd A, pdd B)
{
    if (A.x != B.x)
        return A.x < B.x;
    return A.y < B.y;
}
double dist(pdd a, pdd b)
{
    return abs(sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y)));
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].x >> a[i].y;
    sort(a + 1, a + n + 1);
    vector<pdd> hull;
    hull.push_back(a[1]);
    for (int i = 2; i <= n; i++)
    {
        while (hull.size() >= 2 && ccw(hull[hull.size() - 2], hull[hull.size() - 1], a[i]))
            hull.pop_back();

        hull.push_back(a[i]);
    }
    for (int i = n - 1; i >= 1; i--)
    {
        while (hull.size() >= 2 && ccw(hull[hull.size() - 2], hull[hull.size() - 1], a[i]))
            hull.pop_back();
        hull.push_back(a[i]);
    }
    if (n > 1)
        hull.pop_back();
    cout << fixed << setprecision(2);
    pdd luu;
    luu.x = hull[0].x;
    luu.y = hull[0].y;
    ld cv = 0;
    for (int i = 1; i < hull.size(); i++)
    {
        cv += dist(luu, hull[i]);
        luu = hull[i];
    }
    cv += dist(luu, hull[0]);
    cout << cv;
    return 0;
}
