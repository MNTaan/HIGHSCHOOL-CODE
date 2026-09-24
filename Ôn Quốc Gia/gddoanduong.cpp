#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define endl "\n"
#define x first
#define y second
#define pii pair<double, double>
#define file(name)                    \
    freopen(name ".inp", "r", stdin); \
    freopen(name ".out", "w", stdout);
#define fileTHHB                      \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout)
const int maxN = 1e6 + 10;
using namespace std;
pii p, q;
double a1, b1, c1;
bool check(pair<double, double> m, pii a, pii b)
{
    if (min(a.x, b.x) <= m.x && m.x <= max(a.x, b.x) && min(a.y, b.y) <= m.y && m.y <= max(a.y, b.y)) // xet coi m co nam trong doan thang khong
        return true;
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    cin >> p.x >> p.y >> q.x >> q.y;
    cin >> a1 >> b1 >> c1;
    double a2, b2, c2;
    a2 = q.y - p.y;
    b2 = p.x - q.x;
    c2 = p.y * (q.x - p.x) - p.x * (q.y - p.y);
    double d, dx, dy;
    d = a1 * b2 - a2 * b1;
    dx = b1 * c2 - b2 * c1;
    dy = a2 * c1 - c2 * a1;
    pair<double, double> m;
    m.x = (double)d / dx;
    m.y = (double)d / dy;
    if (d != 0 && check(m, p, q))
    {
        cout << 1 << endl;
        cout << fixed << setprecision(2) << dx / d;
        cout << " ";
        cout << fixed << setprecision(2) << dy / d;
    }
    else
    {
        if (d == 0 && (dx != 0 || dy != 0))
            cout << 2;
        else
            cout << 3;
    }
    return 0;
}
