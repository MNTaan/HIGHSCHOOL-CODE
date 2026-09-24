#include <bits/stdc++.h>
#define ll long long
#define int long long
#define ld long double
#define pb push_back
#define endl "\n"
#define x first
#define y second
#define pii pair<ll, ll>
#define pdd pair<double, double>

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
double dist(pdd a, pdd b)
{
    return abs(sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y)) * 1.00);
}
bool chk(pdd m, pdd a, pdd b)
{
    double t = (a.y - b.y) * m.x + (b.x - a.x) * m.y + (a.x * b.y - b.x * a.y);
    if (t == 0 && min(a.x, b.x) <= m.x && m.x <= max(a.x, b.x) && min(a.y, b.y) <= m.y && m.y <= max(a.y, b.y))
        return true;
    return false;
}
pdd gd(pdd a, pdd b, pdd p, pdd q)
{
    double a1 = (b.y - a.y);
    double a2 = (q.y - p.y);

    double b1 = -(b.x - a.x);
    double b2 = -(q.x - p.x);

    double c1 = a.y * (b.x - a.x) - a.x * (b.y - a.y);
    double c2 = p.y * (q.x - p.x) - p.x * (q.y - p.y);

    double d = a1 * b2 - a2 * b1;
    double dx = c2 * b1 - c1 * b2;
    double dy = a2 * c1 - a1 * c2;

    pair<double, double> m;
    m.x = (double)dx / d * 1.00;
    m.y = (double)dy / d * 1.00;

    if (chk(m, a, b) && chk(m, p, q))
    {
        return m;
    }
    return {0, 0};
}
double surface(pdd m, pdd a, pdd b)
{
    double s1 = 0, s2 = 0;
    s1 += (m.x * a.y);
    s2 += (m.y * a.x);

    s1 += (a.x * b.y);
    s2 += (a.y * b.x);

    s1 += (b.x * m.y);
    s2 += (b.y * m.x);

    return (double)abs(s1 - s2) / 2 * 1.00;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    pdd t[5], n, m;
    cin >> t[1].x >> t[1].y >> t[2].x >> t[2].y >> t[3].x >> t[3].y >> n.x >> n.y >> m.x >> m.y;
    t[4] = t[1];

    pdd xx;
    for (int i = 1; i <= 3; i++) 
    {
        if (gd(n, m, t[i], t[i + 1]) != make_pair(0.00, 0.00))
        {
            xx = gd(n, m, t[i], t[i + 1]);
            break;
        }
    }
    double s1 = 0, s2 = 0;
    for (int i = 1; i <= 3; i++)
    {
        s1 += (t[i].x * t[i + 1].y);
        s2 += (t[i].y * t[i + 1].x);
    }
    double S = (double)abs(s1 - s2) / 2;
    cout << setprecision(5) << fixed;
    double sn = 0;
    for (int i = 1; i <= 3; i++)
    {
        sn += surface(n, t[i], t[i + 1]);
    }
    double sm = 0;
    for (int i = 1; i <= 3; i++)
    {
        sm += surface(m, t[i], t[i + 1]);
    }

    if (S == sn && S == sm)
    {
        cout << dist(n, m);
    }
    else if (S == sn) 
    {
        cout << dist(n, xx);
    }
    else if (S == sm)
    {
        cout << dist(m, xx);
    }
    else
        cout << 0.00000;

    return 0;
}
