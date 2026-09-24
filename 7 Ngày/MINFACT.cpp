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
const int maxN = 1e6 + 69;
const int INF = 1e18;
const int MOD = 0;
using namespace std;
int d[maxN + 10];
void Sieve()
{
    iota(d + 1, d + maxN + 1, 1);
    for (int i = 2; i * i <= maxN; ++i)
        if (d[i] == i)
            for (int j = i * i; j <= maxN; j += i)
                if (d[j] == j)
                    d[j] = i;
}

ll FindN(ll p, ll e)
{
    ll Step = 1, cnt = 0;
    while (cnt * p + 1 <= e)
    {
        Step *= p;
        cnt = cnt * p + 1;
    }
    ll n = 0;
    for (; cnt > 0; cnt /= p)
    {
        ll loop = e / cnt;
        n += Step * loop;
        Step /= p;
        e %= cnt;
    }
    return n;
}

ll FindN2(ll p, ll e)
{
    ll low = 1, high = p * e;
    while (low <= high)
    {
        ll mid = (low + high) / 2;
        ll temp = mid;
        ll cnt = 0;
        for (; temp > 0; temp /= p)
            cnt += temp / p;
        if (cnt < e)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}

ll calc(ll a, ll k)
{
    ll n = 0;
    while (a > 1)
    {
        ll p = d[a], e = 0;
        for (; a % p == 0; a /= p)
            ++e;
        ll temp = FindN(p, e * k);
        if (temp > n)
            n = temp;
    }
    return n;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    file("MINFACT");
    ll T;
    Sieve();
    cin >> T;
    while (T--)
    {
        ll a, k;
        cin >> a >> k;
        cout << calc(a, k) << endl;
    }
    return 0;
}
