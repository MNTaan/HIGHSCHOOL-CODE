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
    const int maxN = 1e6 + 10;
    const int INF = 1e18;
    const int MOD = 998244353;
    using namespace std;
    int n, k;
    int a[maxN];

    int num[maxN], used[maxN], timer, cycle;
    ll ans, f[maxN], p[maxN];

    int dfsCycle(int src)
    {
        int u = src;
        while (true)
        {
            num[u] = ++timer;
            used[u] = src;
            if (used[a[u]] && used[a[u]] != used[src])
                return 0;
            if (num[a[u]])
                return timer - num[a[u]] + 1;
            u = a[u];
        }
        return 0;
    }

    ll binpow(ll a, ll b, ll m)
    {
        ll ans = 1;
        while (b)
        {
            if (b & 1)
                ans = ans * a % m;
            a = a * a % m;
            b >>= 1;
        }
        return ans;
    }
    signed main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        fileTHHB;
        ll t;
        cin>>t;
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        p[1] = k - 1;
        for (int i = 2; i <= n; i++)
        {
            f[i] = (k * p[i - 1] - f[i - 1] + MOD) % MOD;
            p[i] = p[i - 1] * (k - 1) % MOD;
        }
        f[0] = 1;
        f[1] = k;
        ans = 1;
        for (int i = 1; i <= n; i++)
            if (!num[i])
            {
                int x = dfsCycle(i);
                ans = (ans * f[x]) % MOD;
                cycle += x;
            }
        cout << ans * binpow(k - 1, n - cycle, MOD) % MOD;
        return 0;
    }
