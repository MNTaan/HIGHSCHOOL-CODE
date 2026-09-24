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
const int maxN = 1e5 + 5;
const int maxM = 1e6 + 6;
using namespace std;
struct edge
{
    int u, v, f, s;
} e[maxM];
int n, m, q, par[maxN], Rank[maxN], k, v, u, c, test[maxN];
int findset(int u)
{
    if (u == par[u])
        return u;
    return par[u] = findset(par[u]);
}

void Union(int u, int v)
{
    u = findset(u);
    v = findset(v);
    if (u == v)
        return;
    par[v] = u;
    // if (Rank[v] > Rank[u])
    //     swap(Rank[u], Rank[v]);
    // if (Rank[u] == Rank[v])
    //     Rank[u]++;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // fileTHHB;
    ll t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m >> q;
        for (int i = 1; i <= m; i++)
            cin >> e[i].u >> e[i].v >> e[i].f;
        while (q--)
        {
            for (int i = 1; i <= n; i++)
                par[i] = i, Rank[i] = 0;
            cin >> k >> v;
            for (int i = 1; i <= v; i++)
            {
                cin >> u >> c;
                e[u].s = c;
                swap(e[u].f, e[u].s);
                test[i] = u;
            }
            for (int i = 1; i <= m; i++)
                if (e[i].f < e[k].f)
                    Union(e[i].u, e[i].v);
            if (findset(e[k].u) == findset(e[k].v))
                cout << "YES" << endl;
            else
                cout << "NO" << endl;

            for (int i = 1; i <= v; i++)
            {
                u = test[i];
                swap(e[u].f, e[u].s);
            }
        }
    }
    return 0;
}
