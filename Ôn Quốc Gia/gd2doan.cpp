#include <bits/stdc++.h>
#define ll long long
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
pii a, b, p, q;
bool check(pair<double, double> m, pii a, pii b)
{
    if (min(a.x, b.x) <= m.x && m.x <= max(a.x, b.x) && min(a.y, b.y) <= m.y && m.y <= max(a.y, b.y))
        return true;
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    cin >> a.x >> a.y >> b.x >> b.y;
    cin >> p.x >> p.y >> q.x >> q.y;
    double a1 = (b.y - a.y);
    double b1 = (a.x - b.x);
    double a2 = (q.y - p.y);
    double b2 = (p.x - q.x);
    double c1 = a.y * (b.x - a.x) - a.x * (b.y - a.y);
    double c2 = p.y * (q.x - p.x) - p.x * (q.y - p.y);
    double d = a1 * b2 - a2 * b1;
    double dx = c2 * b1 - c1 * b2;
    double dy = a2 * c1 - a1 * c2;
    cout << fixed << setprecision(2);
    pair<double, double> m;
    m.x = (double)dx / d;
    m.y = (double)dy / d;
    if (d != 0 && check(m, a, b) && check(m, p, q))
    {
        cout << 1 << endl;
        cout << m.x << " " << m.y;
    }
    else
        cout << 0;
    return 0;
}
