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
const int maxN = 1e6 + 10;
const int INF = 1e18;
const int MOD = 0;
using namespace std;
pii a[maxN];
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    ll n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].x >> a[i].y;
    a[n + 1] = a[1];
    double s1 = 0, s2 = 0;
    for (int i = 1; i <= n; i++)
    {
        s1 += (a[i].x * a[i + 1].y);
        s2 += (a[i].y * a[i + 1].x);
    }
    double S = (double)abs(s1 - s2) / 2 * 1.00;
    if (s1 - s2 > 0)
        cout << "CCW" << endl;
    else
        cout << "CW" << endl;
    cout << fixed << setprecision(1) << S;
    return 0;
}
