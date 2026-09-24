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
const int maxN = 200000 + 10;
using namespace std;
pii a[maxN];
int n;
bool ccw(pii A, pii B, pii C)
{
    return 1LL * (B.x - A.x) * (C.y - A.y) - 1LL * (C.x - A.x) * (B.y - A.y) > 0;
}
bool cmp(pii A, pii B)
{
    if (A.x != B.x)
        return A.x < B.x;
    return A.y < B.y;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    file("baoloi");
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].x >> a[i].y;
    sort(a + 1, a + n + 1);
    vector<pii> hull;
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
    cout << hull.size() << endl;
    cout << fixed << setprecision(2);
    for (auto it : hull)
        cout << (double)it.x << " " << (double)it.y << endl;
    return 0;
}
