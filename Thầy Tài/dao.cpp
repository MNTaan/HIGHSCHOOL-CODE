// Yo Pi'erre You Wanna Come Out Here
#include <bits/stdc++.h>
#define File(TASK)                         \
    if (fopen(TASK ".inp", "r"))           \
    {                                      \
        freopen(TASK ".inp", "r", stdin);  \
        freopen(TASK ".out", "w", stdout); \
    }
#define FileTHHB                            \
    if (fopen("input.txt", "r"))            \
    {                                       \
        freopen("input.txt", "r", stdin);   \
        freopen("output.txt", "w", stdout); \
    }
#define point pair<double, double>
#define fi first
#define se second
using namespace std;

point operator-(point A, point B)
{
    return {A.first - B.first, A.second - B.second};
}

double operator*(point A, point B)
{
    return (A.first * B.second) - (A.second * B.first);
}

int ccw(point A, point B, point C)
{
    double t = (B - A) * (C - B);
    if (t > 0)
        return 1; // ccw
    if (t < 0)
        return -1; // cw
    return 0;      // not lgbt
}

void extract(point A, point B, double &a, double &b, double &c)
{
    a = B.second - A.second;
    b = A.first - B.first;
    c = -A.first * a + A.second * -b;
}

void extract2(point A, point B, double &a, double &b, double &c)
{
    a = B.second - A.second;
    b = A.first - B.first;
    c = -A.first * (B.second - A.second) + A.second * (B.first - A.first);
}

bool intersec(point A, point B, point X, point Y, point &inter)
{
    double a1, a2, b1, b2, c1, c2, D, Dx, Dy;
    extract(A, B, a1, b1, c1);
    extract(X, Y, a2, b2, c2);
    D = a1 * b2 - a2 * b1;
    Dx = b1 * c2 - b2 * c1;
    Dy = c1 * a2 - c2 * a1;
    if (D != 0)
    {
        inter = {Dx / D, Dy / D};
        return true;
    }
    return false;
}

double Area(const vector<point> &P)
{
    double s = 0;
    int n = P.size();
    for (int i = 0; i < n; i++)
    {
        s += P[i].first * P[(i + 1) % n].second - P[(i + 1) % n].first * P[i].second;
    }
    return abs(s) / 2.0;
}

bool cmp(point A, point B)
{
    if (A.first != B.first)
        return A.first < B.first;
    else
        return A.second < B.second;
}

vector<point> convex_hull(vector<point> P)
{
    sort(P.begin(), P.end(), cmp);
    int nn = P.size();
    vector<point> hull;
    hull.push_back(P[0]);
    for (int i = 1; i < nn; i++)
    {
        while (hull.size() >= 2 && ccw(hull[hull.size() - 2], hull[hull.size() - 1], P[i]) == 1)
        {
            hull.pop_back();
        }
        hull.push_back(P[i]);
    }
    for (int i = nn - 2; i >= 0; i--)
    {
        while (hull.size() >= 2 && ccw(hull[hull.size() - 2], hull[hull.size() - 1], P[i]) == 1)
        {
            hull.pop_back();
        }
        hull.push_back(P[i]);
    }
    if (nn > 1)
        hull.pop_back();
    return hull;
}

double dist(point A, point B)
{
    return sqrt((A.fi - B.fi) * (A.fi - B.fi) + (A.se - B.se) * (A.se - B.se));
}

bool isOn(point A, point B, point M)
{
    return dist(A, M) + dist(M, B) - dist(A, B) < 1e-9;
}

const int N = 1005;

vector<int> adj[N];
point ins[N];
int used[N];
void Solve()
{
    int n, s, t;
    double m;
    memset(used, false, sizeof used);
    cin >> n >> m >> s >> t;
    if (s == t)
    {
        cout << 0;
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> ins[i].fi >> ins[i].se;
    }
    //    cout << '\n';
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                continue;
            if (dist(ins[i], ins[j]) - m <= 1e-9)
            {
                //                cout << i << " " << j << '\n';
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    queue<int> q;
    int trace[N];
    q.push(s);
    used[s] = true;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        if (u == t)
            break;
        for (auto v : adj[u])
        {
            if (!used[v])
            {
                trace[v] = u;
                used[v] = used[u] + 1;
                q.push(v);
            }
        }
    }
    if (!used[t])
    {
        cout << -1;
        return;
    }
    vector<int> vt;
    while (trace[t] != s)
    {
        vt.push_back(trace[t]);
        t = trace[t];
    }
    reverse(vt.begin(), vt.end());
    cout << vt.size() << '\n';
    for (auto i : vt)
        cout << i << " ";
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    File("DAO");

    int T = 1;
    // cin >> T;
    while (T--)
    {
        Solve();
    }
    return 0;
}