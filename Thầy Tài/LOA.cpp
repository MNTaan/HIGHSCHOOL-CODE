#include <bits/stdc++.h>
#define ll long long
#define int long long
#define ld long double
#define pb push_back
#define endl "\n"
#define x first
#define y second
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
pii a[maxN];
double dist(pii a, pii b)
{
    return abs(sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y)));
}
double trongtam(pii a, pii b, pii c)
{
    int s1 = 0, s2 = 0;

    s1 += (a.x * b.y);
    s2 += (a.y * b.x);

    s1 += (b.x * c.y);
    s2 += (b.y * c.x);

    s1 += (c.x * a.y);
    s2 += (c.y * a.x);

    double A = dist(a, b);
    double B = dist(b, c);
    double C = dist(c, a);
    double s = (double)abs(s1 - s2) / 2 * 1.00;
    if (A * A > B * B + C * C)
        return A / 2;
    if (B * B > A * A + C * C)
        return B / 2;
    if (C * C > A * A + B * B)
        return C / 2;
    return (double)(A * B * C) / (4.00 * s);
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].x >> a[i].y;

    double ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            for (int k = j + 1; k <= n; k++)
            {
                ans=max(ans, trongtam(a[i], a[j], a[k]));
            }
    cout << setprecision(3) << fixed << ans;
    return 0;
}
