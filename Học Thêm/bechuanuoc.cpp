#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define fi first
#define se second
#define pii pair<ll, ll>
#define ld long double
#define file(name)                    \
    freopen(name ".inp", "r", stdin); \
    freopen(name ".out", "w", stdout);
#define fileTHHB                      \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout)
const int maxN = 1e5 + 10;
using namespace std;
struct hhcn
{
    ld b, h, w, d;
} a[maxN];
ll n, v;
bool cmp(hhcn x, hhcn y)
{
    return x.b < y.b;
}
bool check(ld mid)
{
    ld V = 0;
    for (int i = 1; i <= n; i++)
    {
        ld dai = a[i].d, cao = a[i].h, rong = a[i].w;
        ld h = a[i].b;
        if (h > mid)
            break;
        ld mn = max((ld)0, min(mid - h, cao));
        V += (dai * rong * mn);
    }
    return (V >= v);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    cin >> n >> v;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].b >> a[i].h >> a[i].w >> a[i].d;
    }
    sort(a + 1, a + n + 1, cmp);
    ld l = 0, r = 1e6 + 4e4, ans = 1e6 + 4e4, eps = 0.001;
    while (l <= r)
    {
        ld mid = (ld)((l + r) / 2);
        // cout<<l<<" "<<r<<endl;
        if (check(mid))
        {
            ans = min(ans, mid);
            r = mid - eps;
        }
        else
            l = mid + eps;
    }
    cout << fixed << setprecision(2) << ans;
    return 0;
}
