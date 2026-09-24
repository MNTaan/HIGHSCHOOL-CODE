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
const int maxN = 1e5 + 10;
using namespace std;
ll n, s1, s2;
ll a[maxN];
bool check(ll x)
{
    ll l = a[n] - x, r = a[n] + x;
    for (int i = n - 1; i >= 1; i--)
    {
        if (a[i] >= l && a[i] <= r)
            l = a[i] - x, r = a[i] + x;
        else
        {
            l = max(l, (a[i] - x));
            r = max(r, (a[i] + x));
        }
    }
    return ((s1 >= l && s1 <= r) || (s2 >= l && s2 <= r));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    file("delivery");
    cin >> n >> s1 >> s2;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    ll l = abs(s1 - s2), r = 1e9;
    while (l <= r)
    {
        ll m = (l + r) / 2;
        if (check(m))
            r = m - 1;
        else
            l = m + 1;
    }
    cout << l;
    return 0;
}
