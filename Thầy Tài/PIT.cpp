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
const int maxN = 100 + 10;
const int INF = 1e18;
const int MOD = 0;
using namespace std;
pii tg[4], a[maxN];
double dientich(pii a, pii b, pii c)
{
    double S = 0;
    S = (a.x - b.x) * (a.y + b.y) + (b.x - c.x) * (b.y + c.y) + (c.x - a.x) * (c.y + a.y);
    return abs(S) / 2 * 1.00;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    cin >> tg[1].x >> tg[1].y >> tg[2].x >> tg[2].y >> tg[3].x >> tg[3].y;
    ll n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].x >> a[i].y;
    double S = dientich(tg[1], tg[2], tg[3]);

    cout << fixed << setprecision(1) << S << endl;
    ll dem = 0;
    for (int i = 1; i <= n; i++)
    {
        double s1 = dientich(a[i], tg[1], tg[2]);
        double s2 = dientich(a[i], tg[2], tg[3]);
        double s3 = dientich(a[i], tg[1], tg[3]);
        if ((s1 + s2 + s3) == S)
            dem++;
    }
    cout << dem;
    return 0;
}
