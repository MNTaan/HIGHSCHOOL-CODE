#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define endl "\n"
#define fi first
#define se second
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
const int maxN = 50000 + 10;
using namespace std;
class Point
{
public:
    int x, y;
};
Point P[maxN];

int compareX(const void *a, const void *b)
{
    Point *p1 = (Point *)a, *p2 = (Point *)b;
    return (p1->x - p2->x);
}
int compareY(const void *a, const void *b)
{
    Point *p1 = (Point *)a, *p2 = (Point *)b;
    return (p1->y - p2->y);
}
double dist(Point p1, Point p2)
{
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}
double bruteForce(Point P[], int n)
{
    double min = FLT_MAX;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            if (dist(P[i], P[j]) < min)
                min = dist(P[i], P[j]);
    return min;
}
double min(double x, double y)
{
    return (x < y) ? x : y;
}
double closest(Point strip[], int size, double d)
{
    double min = d;
    qsort(strip, size, sizeof(Point), compareY);
    for (int i = 0; i < size; ++i)
        for (int j = i + 1; j < size && (strip[j].y - strip[i].y) < min; ++j)
            if (dist(strip[i], strip[j]) < min)
                min = dist(strip[i], strip[j]);
    return min;
}
double calc(Point P[], int n)
{
    if (n <= 3)
        return bruteForce(P, n);
    int mid = n / 2;
    Point midPoint = P[mid];
    double dl = calc(P, mid);
    double dr = calc(P + mid, n - mid);
    double d = min(dl, dr);
    Point strip[n];
    int j = 0;
    for (int i = 0; i < n; i++)
        if (abs(P[i].x - midPoint.x) < d)
            strip[j] = P[i], j++;
    return min(d, closest(strip, j, d));
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    file("pair");
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> P[i].x >> P[i].y;
    qsort(P, n, sizeof(Point), compareX);
    cout << calc(P, n);
    return 0;
}
