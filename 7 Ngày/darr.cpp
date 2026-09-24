#include <bits/stdc++.h>
#define ll long long
#define int long long
#define ld long double
#define pb push_back
#define endl "\n"
#define fi first
#define se second
#define pii pair<ll, ll>
#define FORf(i, a, b) for (ll i = a; i <= b; i++)
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
const int INF = 1e18;
const int MOD = 0;
using namespace std;
ll n, k;
ll a[maxN], summ[maxN];
void subk2()
{
    ll res = -INF;
    FORf(i, 1, n - 1)
    {
        ll varT = summ[i] + 2 * (summ[n] - summ[i]);
        res = max(res, varT);
    }
    cout << res;
}

void subk3n3000()
{
    ll res = -INF;
    FORf(i, 1, n - 2)
        FORf(j, i + 1, n - 1)
            res = max(res, summ[i] + 2 * (summ[j] - summ[i]) + 3 * (summ[n] - summ[j]));
    cout << res;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    file("DARR");
    cin >> n >> k;
    FORf(i, 1, n)
    {
        cin >> a[i];
        summ[i] = summ[i - 1] + a[i];
    }
    if (k == 1)
    {
        cout << summ[n];
        return 0;
    }
    if (k == 2)
    {
        subk2();
        return 0;
    }
    if (k == 3 && n <= 3000)
    {
        subk3n3000();
        return 0;
    }
    if (k == n)
    {
        ll res = 0;
        FORf(i, 1, n) res += i * a[i];
        cout << res;
        return 0;
    }

    return 0;
}
