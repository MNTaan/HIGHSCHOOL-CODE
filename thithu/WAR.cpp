#include <bits/stdc++.h>
#ifdef LOCAL
#include <cpp-dump/cpp-dump.hpp>
#define debug(...) cpp_dump(__VA_ARGS__)
#else
#define debug(...)
#endif // LOCAL
using namespace std;
#define ll long long
#define int long long
#define endl '\n'
#define all(v) (v).begin(), (v).end()
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back

template <class T>
int getbit(T s, int i) { return (s >> i) & 1; }
template <class T>
T onbit(T s, int i) { return s(T(1) << i); }
template <class T>
T offbit(T s, int i) { return s & (~(T(1) << i)); }
template <class T>
int cntbit(T s) { return __builtin_popcountll(s); }

const int MOD = 1e9 + 7;
template <typename T>
bool maximize(T &res, const T &val)
{
    if (res < val)
    {
        res = val;
        return true;
    };
    return false;
}
template <typename T>
bool minimize(T &res, const T &val)
{
    if (res > val)
    {
        res = val;
        return true;
    };
    return false;
}
const int maxn = 2e5 + 50;
const int cs = 400 + 50;
const int INF = 1e9;
const ll LINF = 1e18;
int n, m;
int a[cs][cs];
vector<int> adj[cs];
/** -----EXTENSIVE FUNCTIONS----- **/

int bfs(int s, int t, vector<int> &par)
{
    fill(all(par), -1);
    par[s] = s;
    queue<pii> q;
    q.push({s, LINF});

    while (!q.empty())
    {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int nx : adj[cur])
        {
            if (par[nx] == -1 && a[cur][nx] > 0)
            {
                par[nx] = cur;
                int new_flow = min(flow, a[cur][nx]);
                if (nx == t)
                    return new_flow;
                q.push({nx, new_flow});
            }
        }
    }
    return 0;
}

int edmonds_karp(int s, int t)
{
    int flow = 0;
    vector<int> parent(n);
    int new_flow;

    while (new_flow = bfs(s, t, parent))
    {
        flow += new_flow;
        int cur = t;
        while (cur != s)
        {
            int prev = parent[cur];
            a[prev][cur] -= new_flow;
            a[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return flow;
}

void Solve()
{
    int T;
    cin >> T >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb(v);
        adj[v].pb(u);
        a[u][v] += w;
        a[v][u] += w;
    }

    if (T == 1)
    {
        int cost = LINF;
        for (int u = 0; u < n; u++)
        {
            for (int v = u + 1; v < n; v++)
            {
                int tmp[cs][cs];
                memcpy(tmp, a, sizeof(a));

                minimize(cost, edmonds_karp(u, v));
                memcpy(a, tmp, sizeof(a));
            }
        }
        cout << cost << endl;
    }
    else if (T == 2)
    {
        int cost = 0;
        int cnt = 0;

        for (int u = 0; u < n; u++)
        {
            for (int v = u + 1; v < n; v++)
            {
                int tmp[cs][cs];
                memcpy(tmp, a, sizeof a);

                cost += edmonds_karp(u, v);
                cnt++;
                memcpy(a, tmp, sizeof a);
            }
        }
        cout << cost * n * (n - 1) / cnt << endl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifdef LOCAL
    freopen("TASK.inp", "r", stdin);
    freopen("TASK.out", "w", stdout);
#else
#define name "WAR"
    if (fopen(name ".inp", "r"))
    {
        freopen(name ".inp", "r", stdin);
        freopen(name ".out", "w", stdout);
    }
#endif // LOCAL
    auto TIME1 = chrono::steady_clock::now();
    int T = 1;
    // cin >> T;
    while (T--)
        Solve();
    auto TIME2 = chrono::steady_clock::now();
    auto DIFF = TIME2 - TIME1;
    cerr << "Time: " << fixed << setprecision(8) << chrono::duration<double>(DIFF).count() << "s";
    return 0;
}