#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <cpp-dump-main/cpp-dump.hpp>
#define debug(...) cpp_dump(__VA_ARGS__)
CPP_DUMP_SET_OPTION_GLOBAL(max_line_width, 100);
CPP_DUMP_SET_OPTION_GLOBAL(log_label_func, cpp_dump::log_label::filename());
CPP_DUMP_SET_OPTION_GLOBAL(enable_asterisk, true);
#else
#define debug(...)
#endif // LOCAL

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ll mod = 1e9 + 7;
template <class T>
bool ckmin(T &a, T b) { return a < b ? 1 : a = b, 0; }
template <class T>
bool ckmax(T &a, T b) { return a > b ? 1 : a = b, 0; }
template <class T>
void add(T &a, T b, T m = mod) { a = (a + b) % m; };
template <class T>
void mul(T &a, T b, T m = mod) { a = a * b % m; }

const int N = 21;
int n, m, a[N], b[N];

namespace sub1
{
    void solve()
    {
        ll ans = 0;
        for (int mask = 0; mask < (1 << m); mask++)
        {
            ll sum = 0;
            for (int i = 0; i < m; i++)
                if (mask >> i & 1)
                    sum += b[i + 1];
            if (sum == a[1])
                ans++;
        }
        cout << ans << '\n';
    }
}

namespace sub2
{
    ll dp[21][1010][1010];

    ll cal(int i, int sum1, int sum2)
    {
        if (i == m + 1 && sum1 == a[1] && sum2 == a[2])
            return 1;
        if (i == m + 1)
            return 0;
        if (dp[i][sum1][sum2] != -1)
            return dp[i][sum1][sum2];

        ll res = 0;
        if (sum1 + b[i] <= a[1])
            res += cal(i + 1, sum1 + b[i], sum2);
        if (sum2 + b[i] <= a[2])
            res += cal(i + 1, sum1, sum2 + b[i]);
        res += cal(i + 1, sum1, sum2);
        return dp[i][sum1][sum2] = res % mod;
    }

    void solve()
    {
        memset(dp, -1, sizeof dp);
        cout << cal(1, 0, 0) << '\n';
    }
}

namespace sub3
{
    ll c[1 << 10][21], dp[1 << 10][21];
    void solve()
    {
        memset(c, 0, sizeof c);
        memset(dp, 0, sizeof dp);
        for (int i = 1; i <= n; i++)
        {
            for (int mask = 0; mask < (1 << m); mask++)
            {
                ll sum = 0;
                for (int j = 0; j < m; j++)
                    if (mask >> j & 1)
                        sum += b[j + 1];
                if (sum == a[i])
                    c[mask][i] = 1;
            }
        }
        ll ans = 0;
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int mask = 0; mask < (1 << m); mask++)
            {
                for (int subMask = mask; subMask; subMask = (subMask - 1) & mask)
                    if (c[subMask][i])
                        add(dp[mask][i], dp[subMask ^ mask][i - 1]);
                if (i == n)
                    add(ans, dp[mask][i]);
            }
        }
        cout << ans << '\n';
    }
}

namespace sub4
{
    ll dp[1 << 20][21];

    ll calc(int mask, int i, int sum, int j)
    {
        if (i > n)
            return 1;
        if (sum == a[i])
            return calc(mask, i + 1, 0, 0);
        if (dp[mask][j] != -1)
            return dp[mask][j];

        ll ans = 0;
        for (int jj = j; jj < m; jj++)
            if ((mask >> jj & 1) == 0 && sum + b[jj + 1] <= a[i])
                add(ans, calc(mask | (1 << jj), i, sum + b[jj + 1], jj + 1));
        return dp[mask][j] = ans;
    }

    void solve()
    {
        memset(dp, -1, sizeof dp);
        cout << calc(0, 1, 0, 0) << '\n';
    }
}

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
        cin >> b[i];
    if (n == 1)
        return sub1::solve();
    if (n == 2)
        return sub2::solve();
    if (m <= 10)
        return sub3::solve();
    sub4::solve();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifdef LOCAL
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
#else
#define file "name"
    if (fopen(file ".inp", "r"))
    {
        freopen(file ".inp", "r", stdin);
        freopen(file ".out", "w", stdout);
    }
#endif // LOCAL

    int T;
    T = 1;
    if (1)
        cin >> T;
    for (int i = 1; i <= T; i++)
    {
        solve();
    }
}
