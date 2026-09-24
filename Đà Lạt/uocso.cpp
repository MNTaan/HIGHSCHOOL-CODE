#include <bits/stdc++.h>
#define ll long long
#define int long long
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
const int maxN = 200000 + 10;
const int INF = 1e18;
const int MOD = 0;
using namespace std;
int laymu(int d, int n)
{

    int no = n / d;

    int re = no;

    for (int p = 2; p * p <= no; ++p)
    {
        if (no % p == 0)
        {
            while (no % p == 0)
                no /= p;
            re -= re / p;
        }
    }
    if (no > 1)
        re -= re / no;
    return re;
}
int tinh(int n)
{
    int res = 0;

    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            int d1 = i;
            int d2 = n / i;
            res += d1 * laymu(d1, n);
            if (d1 != d2)
                res += d2 * laymu(d2, n);
        }
    }

    return res;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    ll n, k;
    cin >> n >> k;

    map<int, int> cnt;
    vector<int> d;
    for (int i = 1; i * i < n; i++)
    {
        if (n % i == 0)
        {
            d.push_back(i);
            if (i * i != n)
                d.push_back(n / i);
        }
    }
    sort(d.begin(), d.end(), greater<int>());
    for (int u : d)
    {
        cnt[u] += k / u;
        for (int v : d)
            if (u != v && u % v == 0)
                cnt[v] -= cnt[u];
    }
    int ans = 0;
    for (auto p : cnt)
        ans += p.first * p.second;
    cout << ans;

    return 0;
}
