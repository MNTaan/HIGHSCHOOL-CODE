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
const int MOD = 0;
const ll LINF = 227 * 1997;
using namespace std;
int calc(int n, vector<pii> &bidir, vector<pii> &unidir)
{
    vector<vector<int>> adj(n + 1);
    for (const auto &edge : bidir)
    {
        adj[edge.fi].pb(edge.se);
        adj[edge.se].pb(edge.fi);
    }
    for (const auto &edge : unidir)
    {
        adj[edge.fi].pb(edge.se);
    }

    int max_path = 0;

    for (int start = 1; start <= n; ++start)
    {
        map<pii, int> dist;
        queue<pii> q;

        for (int v : adj[start])
        {
            q.push({v, start});
            dist[{v, start}] = 1;
        }
        while (!q.empty())
        {
            int u = q.front().fi;
            int prev = q.front().se;
            q.pop();

            for (int v : adj[u])
            {
                if (v != prev && dist[{v, u}] < dist[{u, prev}] + 1)
                {
                    dist[{v, u}] = dist[{u, prev}] + 1;
                    q.push({v, u});
                    max_path = max(max_path, dist[{v, u}]);

                    if (max_path > LINF)
                    {
                        return -1;
                    }
                }
            }
        }
    }

    return max_path;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    file("FAKERFMVP");
    ll T;
    cin >> T;
    while (T--)
    {
        int n, m, p;
        cin >> n >> m >> p;
        vector<pii> bidir(m), unidir(p);
        for (int i = 0; i < m; ++i)
        {
            cin >> bidir[i].fi >> bidir[i].se;
        }
        for (int i = 0; i < p; ++i)
        {
            cin >> unidir[i].fi >> unidir[i].se;
        }
        cout << calc(n, bidir, unidir) << endl;
    }
    return 0;
}
