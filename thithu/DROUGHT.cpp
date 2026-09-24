#include <bits/stdc++.h>
#define ll long long
#define int long long
#define ld long double
#define pb push_back
#define endl "\n"
#define fi first
#define se second
#define all(v) (v).begin(), (v).end()
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
const double EPS = 1e-6;
using namespace std;
struct Point
{
    int x, y, a;
};
int n;
double distance(Point a, Point b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

bool dfs(int u, vector<double> &water, vector<Point> &points, vector<bool> &vis)
{
    vis[u] = true;
    for (int v = 0; v < n; v++)
    {
        if (!vis[v])
        {
            double d = distance(points[u], points[v]);
            if (water[u] > d)
            {
                water[v] += water[u] - d;
                water[u] = d;
                if (dfs(v, water, points, vis))
                    return true;
                water[v] -= water[u] - d;
                water[u] = d;
            }
        }
    }
    return all_of(all(water), [&](double w)
                  { return w >= 0; });
}

bool check(double mid, vector<Point> &points, int n)
{
    vector<double> water(n);
    vector<bool> vis(n, false);
    for (int i = 0; i < n; ++i)
    {
        water[i] = points[i].a - mid;
    }
    bool ans = dfs(0, water, points, vis);
    return ans;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    file("DROUGHT");
    cin >> n;
    vector<Point> points(n);
    for (int i = 0; i < n; ++i)
        cin >> points[i].x >> points[i].y >> points[i].a;

    double l = 0, r = 1e9, res = 0;
    while (r - l > EPS)
    {
        double mid = (l + r) / 2;
        if (check(mid, points, n))
        {
            res = mid;
            l = mid;
        }
        else
        {
            r = mid;
        }
    }

    cout << fixed << setprecision(6) << res << endl;
    return 0;
}
