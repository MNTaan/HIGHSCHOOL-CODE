#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define endl "\n"
#define fi first
#define se second
#define pii pair<ll, ll>
#define file(name)                    \
    freopen(name ".inp", "r", stdin); \
    freopen(name ".out", "w", stdout);
#define fileTHHB                      \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout)
const int maxN = 200000 + 10;
using namespace std;
struct t
{
    ll fi, se, th, dem;
} a[maxN];
bool cmp(t a, t b)
{
    return a.se < b.se;
}
ll m, n, d = 0;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    file("buy");
    cin >> m >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].fi >> a[i].se;
        a[i].th = i;
    }
    sort(a + 1, a + n + 1, cmp);    
    for (int i = 1; i <= n; i++)
    {
        while (a[i].fi > 0)
        {
            if (!m)
                break;
            a[i].dem++;
            a[i].fi--;
            m--;
            d += a[i].se;
        }
    }
    cout << d << endl;
    return 0;
}
