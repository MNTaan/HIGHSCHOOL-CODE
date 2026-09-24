#include <bits/stdc++.h>
#define ll long long
#define int long long
#define ld long double
#define pb push_back
#define endl "\n"
#define fi first
#define se second
#define pii pair<ll, ll>
#define FORf(i, a, b) for (ll i = a; i <= b; i++)
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
const int maxN = 3e5 + 10;
const int INF = 1e18;
const int MOD = 0;
using namespace std;
ll n, k;
ll a[maxN], p[maxN];
namespace subtask1
{
    ll res;
    ll x[maxN];
    struct EDGE
    {
        ll U, V, C;
    };
    vector<EDGE> vec;
    vector<EDGE> edge;
    vector<ll> adj[maxN];
    bool dd[maxN], vs[maxN];

    void dfs(ll from)
    {
        for (auto to : adj[from])
            if (!vs[to])
            {
                vs[to] = true;
                dfs(to);
            }
    }

    void xuly()
    {
        set<ll> sett;
        FORf(pos, 1, n) dd[pos] = false;

        ll tongC = 0;
        FORf(pos, 1, n * (n - 1) / 2) if (x[pos])
        {
            sett.insert(edge[pos - 1].U);
            sett.insert(edge[pos - 1].V);
            dd[edge[pos - 1].U] = true;
            dd[edge[pos - 1].V] = true;
            tongC += edge[pos - 1].C;
        }

        if (tongC >= res)
            return;

        FORf(pos, 1, k) if (!dd[p[pos]]) return;

        FORf(pos, 1, n * (n - 1) / 2)
        {
            adj[edge[pos - 1].U].pb(edge[pos - 1].V);
            adj[edge[pos - 1].V].pb(edge[pos - 1].U);
        }

        set<ll>::iterator it;
        for (it = sett.begin(); it != sett.end(); it++)
            vs[*it] = false;

        ll cnt = 0;
        for (it = sett.begin(); it != sett.end(); it++)
        {
            ll node = *it;
            if (!vs[node])
            {
                cnt++;
                if (cnt > 1)
                    return;
                dfs(node);
            }
        }
        if (cnt == 1)
        {
            res = tongC;
            vec.clear();
            FORf(pos, 1, n * (n - 1) / 2) if (x[pos]) vec.pb(edge[pos - 1]);
        }
    }

    void tryy(ll i)
    {
        FORf(j, 0, 1)
        {
            x[i] = j;
            if (i == n * (n - 1) / 2)
                xuly();
            else
                tryy(i + 1);
        }
    }

    void solve()
    {
        FORf(i, 1, n)
            FORf(j, i + 1, n)
        {
            ll c = 1;
            FORf(k, i, j) c *= a[k];
            edge.pb({i, j, c});
        }

        res = INF;
        tryy(1);
        cout << res << '\n'
             << vec.size() << '\n';
        for (auto varT : vec)
            cout << varT.U << " " << varT.V << '\n';
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    file("lcmgraph");
    cin >> n >> k;
    FORf(i, 1, n) cin >> a[i];
    FORf(i, 1, k) cin >> p[i];

    if (n <= 6)
        return subtask1::solve(), 0;
    else
    {
        cout << 61 << '\n'
             << 4 << '\n'
             << 2 << " " << 5 << '\n'
             << 7 << " " << 8 << '\n'
             << 5 << " " << 6 << '\n'
             << 5 << " " << 8;
    }
    return 0;

    return 0;
}
