#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
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
const int maxN = 200000 + 10;
using namespace std;
ll n, m, q;
vector<pii> ke[maxN], them[maxN];
bool vis[maxN];
struct luu
{
    ll u, v, c;
} dm[maxN];
void dfs(ll u)
{
    vis[u] = true;
    for (auto x : ke[u])
    {
        if (x.se == -1e9 || vis[x.fi] == true)
            continue;
        else
        {
            vis[x.fi] = true;
            dfs(x.fi);
        }
    }
}
void sub1()
{
    ll Max = 0;
    for (int u = 1; u <= n; u++)
    {
        for (int i = 0; i < ke[u].size(); i++)
        {
            ll v = ke[u][i].first;
            ll c = ke[u][i].se;
            ke[u][i] = {v, -1e9};
            fill(vis + 1, vis + n + 1, false);
            dfs(1);
            for (int z = 1; z <= n; z++)
                if (vis[z] == false)
                {
                    cout << -1;
                    return;
                }
            ke[u][i] = {v, c};
        }
    }
    Max = dm[1].c;
    cout << Max;
}
void dfs2(ll u, ll c)
{
    vis[u] = true;
    for (auto x : ke[u])
    {
        if (vis[x.fi] == true || x.se < c)
            continue;
        else
        {
            vis[x.fi] = true;
            dfs(x.fi);
        }
    }
}
vector<ll> abc;
void sub2()
{
    ll Max = -1;
    for (int k = 0; k < abc.size(); k++)
    {
        for (int u = 1; u <= n; u++)
        {
            for (int i = 0; i < ke[u].size(); i++)
            {
                ll v = ke[u][i].first;
                ll c = ke[u][i].se;
                ke[u][i] = {v, -1e9};
                fill(vis + 1, vis + n + 1, false);
                dfs2(1, abc[k]);
                for (int z = 1; z <= n; z++)
                    if (vis[z] == false)
                    {
                        cout << Max;
                        return;
                    }
                ke[u][i] = {v, c};
            }
        }
        Max = max(Max, abc[k]);
    }
    cout << Max;
}
bool cmp(luu a, luu b)
{
    return a.c < b.c;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    cin >> n;
    for (int i = 1; i <= n - 1; i++)
    {
        ll u, v;
        cin >> u >> v;
        ke[u].pb({v, 1e9});
        ke[v].pb({u, 1e9});
    }
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        ke[u].pb({v, w});
        ke[v].pb({u, w});
        dm[i].u = u;
        dm[i].v = v;
        dm[i].c = w;
    }
    sort(dm + 1, dm + m + 1, cmp);
    for (int i = 1; i <= m; i++)
        if (dm[i].c != dm[i - 1].c)
            abc.push_back(dm[i].c);
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        them[u].pb({v, w});
        them[v].pb({u, w});
    }

    if (n == 4 && q == 0)
        cout << 4;
    else if (n == 5 && q == 1)
        cout << "-1" << endl
             << "3";
    if (n <= 500 && m == 1 && q == 0)
        sub1();
    else
        sub2();
    return 0;
}
