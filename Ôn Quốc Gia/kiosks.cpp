#include <bits/stdc++.h>
#define name "TASK"
#define int long long
const int N = 2e5 + 69;
const int MOD = 1e9 + 7;
using namespace std;
int n, k;
vector<int> c;
vector<int> adj[N];
int bit(int mask, int i)
{
    if (i > 20)
        return 0;
    return (mask >> i) & 1;
}
void dfs(int u, int par, vector<int> a[], vector<int> &c, vector<int> &f, int cant)
{
    if (bit(cant, c[u]))
        f[u] = 0;
    else
        f[u] = 1;
    for (auto v : a[u])
    {
        if (v == par)
            continue;
        dfs(v, u, a, c, f, cant);

        int cnt = (1 + f[v]) % MOD;
        f[u] = (f[u] * cnt) % MOD;
    }
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if (fopen(name ".inp", "r"))
    {
        freopen(name ".inp", "r", stdin);
        freopen(name ".out", "w", stdout);
    }
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        x--;
        c.push_back(x);
    }
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int res = 0;
    for (int cant = 0; cant < (1 << k); cant++)
    {
        vector<int> f(n, 0);
        dfs(0, -1, adj, c, f, cant);

        int sum = accumulate(f.begin(), f.end(), 0LL) % MOD;

        if (__builtin_popcount(cant) % 2 == 0)
            res = (res + sum) % MOD;
        else
            res = (res - sum + MOD) % MOD;
    }
    cout << res;
    return 0;
// lên cho ae con hàng còn lại
}