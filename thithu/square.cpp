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
const int MOD = 1e9 + 9999;
using namespace std;
ll n, m, t;
struct DSU
{
    vector<int> parent, Rank, parity;

    DSU(int n)
    {
        parent.resize(n);
        Rank.resize(n, 0);
        parity.resize(n, 0);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int u)
    {
        if (u != parent[u])
        {
            int root = find(parent[u]);
            parity[u] ^= parity[parent[u]];
            parent[u] = root;
        }
        return parent[u];
    }

    bool unite(int u, int v, int p)
    {
        int pu = find(u), pv = find(v);
        if (pu == pv)
        {
            return (parity[u] ^ parity[v]) == p;
        }
        if (Rank[pu] < Rank[pv])
            swap(pu, pv);
        parent[pv] = pu;
        parity[pv] = parity[u] ^ parity[v] ^ p;
        if (Rank[pu] == Rank[pv])
            Rank[pu]++;
        return true;
    }
};

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    file("square");
    cin >> n >> m >> t;

    vector<pair<pii, int>> a(t);
    for (int i = 0; i < t; i++)
    {
        int u, v, x;
        cin >> u >> v >> x;
        a[i] = {{u - 1, v - 1}, x};
    }

    DSU dsu(2);
    for (auto it : a)
    {
        int u = it.fi.fi;
        int v = it.fi.se;
        int x = it.se;
        int type = (u + v) % 2;
        if (!dsu.unite(type, 1 - type, x))
        {
            cout << 0 << endl;
            return 0;
        }
    }

    ll totalCells = n * m;
    ll halfCells = totalCells / 2;
    if (n * m % 2 != 0)
        halfCells++;

    ll res = 1;
    for (int i = 0; i < 2; i++)
    {
        if (dsu.find(i) == i)
            res = (res * 2) % MOD;
    }

    cout << res << endl;

    return 0;
}
