/**
 *    author:  mamion
 *    created: Saturday 2024-11-02
 **/

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

struct matcher
{
    const int oo = 100000000;
    int m, n;
    vector<int> mx, my, dist;
    vector<vector<int>> ke;
    int matched;

    matcher(int m, int n) : m(m), n(n),
                            mx(m + 1, 0), my(n + 1, 0), dist(m + 1),
                            ke(m + 1),
                            matched(0) {}

    void add_edge(int u, int v)
    {
        ke[u].push_back(v);
    }

    bool bfs()
    {
        queue<int> Q;
        for (int u = 1; u <= m; u++)
        {
            if (!mx[u])
            {
                dist[u] = 0;
                Q.push(u);
            }
            else
            {
                dist[u] = oo;
            }
        }

        bool found = false;
        while (!Q.empty())
        {
            int u = Q.front();
            Q.pop();
            for (int v : ke[u])
            {
                if (!my[v])
                {
                    found = true;
                }
                else if (dist[my[v]] == oo)
                {
                    dist[my[v]] = dist[u] + 1;
                    Q.push(my[v]);
                }
            }
        }

        return found;
    }

    bool dfs(int u)
    {
        if (dist[u] == oo)
            return false;
        for (int v : ke[u])
        {
            if (!my[v] || (dist[my[v]] == dist[u] + 1 && dfs(my[v])))
            {
                mx[u] = v;
                my[v] = u;
                return true;
            }
        }
        return false;
    }

    void match()
    {
        while (bfs())
        {
            for (int u = 1; u <= m; u++)
                if (!mx[u])
                    matched += dfs(u);
        }
    }
};

const ll mod = 1e9 + 7;
template <class T>
bool ckmin(T &a, T b) { return a < b ? 1 : a = b, 0; }
template <class T>
bool ckmax(T &a, T b) { return a > b ? 1 : a = b, 0; }
template <class T>
void add(T &a, T b, T m = mod) { a = (a + b) % m; };
template <class T>
void mul(T &a, T b, T m = mod) { a = a * b % m; }

const int N = 110;
ll m, n, p, c, a[N], b[N];
pair<ll, ll> notPrint[N * N];

namespace sub1
{
    void solve()
    {
        ll ok[m + 1];
        memset(ok, 0, sizeof ok);
        for (ll i = 1; i <= c; i++)
            ok[notPrint[i].first] = 1;
        ll maxQ = 0;
        for (ll i = 1; i <= m; i++)
            if (ok[i] == 0)
                maxQ = max(maxQ, a[i]);
        if (maxQ == 0)
            cout << -1 << '\n';
        else
            cout << b[1] + (p + maxQ - 1) / maxQ - 1 << '\n';
    }
}

namespace sub2
{
    void solve()
    {
        if (c)
        {
            cout << -1 << '\n';
            return;
        }
        sort(b + 1, b + 1 + n);
        ll s = (p + a[1] - 1) / a[1], ans = 0;
        for (int i = 1; i <= n; i++)
            ans = max(ans, b[i] + (n - i + 1) * s);
        cout << ans - 1 << '\n';
    }
}

namespace sub3
{
}

namespace sub4
{
    ll ok[N][N];
    bool check(ll d)
    {
        for (int i = 1; i <= c; i++)
            ok[notPrint[i].first][notPrint[i].second] = 1;
        matcher mc(m * n, n);
        ll vert = 1;
        for (int i = 1; i <= m; i++)
        {
            ll s = (p + a[i] - 1) / a[i];
            ll cur = d, cnt = 0;
            while (cnt < n)
            {
                cur -= s;
                cnt++;
                for (int j = 1; j <= n; j++)
                {
                    if (ok[i][j])
                        continue;
                    if (b[j] <= cur + 1)
                        mc.add_edge(vert, j);
                }
                vert++;
            }
        }
        mc.match();
        return mc.matched == n;
    }

    void solve()
    {
        ll ans = -1;
        for (ll l = 1, r = 1e15; l <= r;)
        {
            ll m = (l + r) / 2;
            if (check(m))
            {
                ans = m;
                r = m - 1;
            }
            else
                l = m + 1;
        }
        cout << ans << '\n';
    }
}

void solve()
{
    cin >> m >> n >> p >> c;
    for (ll i = 1; i <= m; i++)
        cin >> a[i];
    for (ll i = 1; i <= n; i++)
        cin >> b[i];
    for (ll i = 1; i <= c; i++)
        cin >> notPrint[i].first >> notPrint[i].second;
    //    if (n == 1) return sub1::solve();
    //    if (m == 1) return sub2::solve();
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
    if (0)
        cin >> T;
    for (int i = 1; i <= T; i++)
    {
        solve();
    }
}
