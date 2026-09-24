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
using namespace std;
ll n, cnt, P[maxN], vis[maxN], ok, low[maxN], num[maxN];
vector<pii> adj[maxN];
stack<ll> st;
void dfs(ll u, ll par)
{
    low[u] = num[u] = ++low[0];
    st.push(u);
    for (auto v : adj[u])
    {
        if (v.se == par)
            continue;
        if (num[v.fi])
            low[u] = min(low[u], num[v.fi]);
        else
        {
            dfs(v.fi, v.se);
            low[u] = min(low[u], low[v.fi]);
        }
    }
    if (low[u] == num[u])
    {
        ll cnt = 0, mi = 10;
        ll v = 0;
        while (v != u)
        {
            v = st.top();
            st.pop();
            ++cnt;
            mi = min(mi, (ll)adj[v].size());
            low[v] = num[v] = n + 1;
        }
        if (cnt > 1 && mi == 2)
            ok = 1;
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        ll u;
        cin >> u;
        adj[u].pb({i, i});
        adj[i].pb({u, i});
    }
    dfs(1, 0);
    ll res = n - 1 - ok;
    vector<ll> vec;
    for (int i = 1; i <= n; i++)
    {
        if (adj[i].size() == 1)
            res-=1;
    }
    cout << max((ll)0, res) << endl;
    return 0;
}
