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
const int maxN = 1e4 + 10;
const int INF = 1e18;
const int MOD = 0;
using namespace std;
ll a, b, prime[maxN];
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    ll t;

    cin >> t;
    while (t--)
    {

        cin >> a >> b;
        map<ll, ll> cnt;

        for (int i = 2; i * i <= a; i++)
        {
            while (a % i == 0)
            {
                a /= i;
                cnt[i] ^= 1;
            }
        }
        if (a > 1)
            cnt[a] ^= 1;
        for (int i = 2; i * i <= b; i++)
        {
            while (b % i == 0)
            {
                b /= i;
                cnt[i] ^= 1;
            }
        }
        if (b > 1)
            cnt[b] ^= 1;

        vector<ll> num;
        for (auto p : cnt)
            if (p.second)
                num.push_back(p.first);
        int n = num.size();

        ll ans = 1e18, ansA, ansB;
        for (int i = 0; i < (1 << n); i++)
        {
            ll A = 1, B = 1;
            for (int j = 0; j < n; j++)
                if (i >> j & 1)
                    B *= num[j];
                else
                    A *= num[j];
            if (ans > A + B)
            {
                ans = A + B;
                ansA = A;
                ansB = B;
            }
        }
        cout << ansA << ' ' << ansB << '\n';
    }
    return 0;
}
