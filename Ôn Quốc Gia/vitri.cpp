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
#define pdd pair<double, double>
const int maxN = 2e5 + 69;
const int INF = 1e18;
const int MOD = 0;
using namespace std;
int n;
pdd a[maxN], m;
bool chk(pdd m, pdd a, pdd b)
{
    double t = (a.y - b.y) * m.x + (b.x - a.x) * m.y + (a.x * b.y - b.x * a.y);
    if (t == 0 && min(a.x, b.x) <= m.x && m.x <= max(a.x, b.x) && min(a.y, b.y) <= m.y && m.y <= max(a.y, b.y))
        return true;
    return false;
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
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].x >> a[i].y;
    cin >> m.x >> m.y;
    a[n + 1] = a[1];

    int dem = 0;
    for (int i = 1; i <= n; i++)
    {
        pdd aa = a[i];
        pdd bb = a[i + 1];

        if (chk(m, aa, bb))
        {
            cout << "ON ";
            int id2 = 0;
            if (i + 1 > n)
                id2 = 1;
            else
                id2 = i + 1;
            cout << "A" << i << "A" << id2 << endl;
            dem++;
        }
    }
    if (dem > 0)
        return 0;

    double s1 = 0, s2 = 0;
    for (int i = 1; i <= n; i++)
    {
        s1 += (a[i].x * a[i + 1].y);
        s2 += (a[i].y * a[i + 1].x);
    }
    double S = (double)abs(s1 - s2) / 2 * 1.00;

    double cmp = 0;
    for (int i = 1; i <= n; i++)
    {
        double xx = (double)surface(m, a[i], a[i + 1]) * 1.00;
        cmp += xx;
    }
    if (cmp * 1.00 == S * 1.00)
        cout << "IN";
    else
        cout << "OUT";
    return 0;
}
