#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define fi first
#define se second
#define pii pair<double, double>
#define file(name)                    \
    freopen(name ".inp", "r", stdin); \
    freopen(name ".out", "w", stdout);
#define fileTHHB                      \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout)
const int maxN = 1e6 + 10;
using namespace std;
double a1, b1, c1, a2, b2, c2;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    cin >> a1 >> b1 >> c1;
    cin >> a2 >> b2 >> c2;
    double d, dx, dy;
    d = a1 * b2 - a2 * b1;
    dx = c2 * b1 - c1 * b2;
    dy = a2 * c1 - a1 * c2;
    if (d != 0)
    {
        cout << 1 << endl;
        if (dx / d == 0)
            cout << fixed << setprecision(2) << 0.00;
        else
            cout << fixed << setprecision(2) << dx / d;
        cout << " ";
        if (dy / d == 0)
            cout << fixed << setprecision(2) << 0.00;
        else
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
