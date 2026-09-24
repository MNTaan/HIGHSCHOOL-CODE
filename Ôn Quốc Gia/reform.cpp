#include <bits/stdc++.h>
#define ll long long
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
const int mod = 1e9 + 7;
const int maxn = 1e6;
const int base = 31;
using namespace std;
int n, m;
vector<int> adj[maxn + 1];
int used[maxn + 1], f[maxn + 1];

void dfs(int u, int &cnt)
{
    ++cnt;
    f[u] = 1;
    used[u] = 1;
    for (int v : adj[u])
    {
        if (used[v] == 0)
        {
            dfs(v, cnt);
            f[u] += f[v];
        }
    }
}

int low[maxn + 1], num[maxn + 1], timer = 0, cau = 0;
set<pii> br;
void tj(int u, int par)
{
    low[u] = num[u] = ++timer;
    for (int v : adj[u])
    {
        if (v == par)
            continue;
        if (num[v] == 0)
        {
            tj(v, u);
            low[u] = min(low[u], low[v]);
            if (num[v] == low[v])
            {
                br.insert({u, v});
                ;
            }
        }
        else
        {
            low[u] = min(low[u], num[v]);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int cnt = 0, dem = 0;
    int s1 = 0, s2 = 0;
    for (int i = 1; i <= n; i++)
    {
        if (used[i] == 0)
        {
            ++cnt;
            dem = 0;
            dfs(i, dem);
            if (cnt == 1)
                s1 = dem;
            else if (cnt == 2)
                s2 = dem;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (num[i] == 0)
            tj(i, i);
    }

    cau = br.size();

    if (cnt >= 3)
        return cout << 0, 0;
    if (cnt == 1)
    {
        int ans = ((n * (n - 1) / 2) - m) * (m - cau);
        for (auto it : br)
        {
            ans += (f[it.second] * (n - f[it.second])) - 1;
        }
        cout << ans << "\n";
    }
    else
    {
        cout << s1 * s2 * (m - cau);
    }

    return 0;
}
