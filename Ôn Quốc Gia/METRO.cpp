#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define fi first
#define se second
#define pii pair<ll, ll>
#define piii pair<ll, pii>
#define file(name)                    \
    freopen(name ".inp", "r", stdin); \
    freopen(name ".out", "w", stdout);
#define fileTHHB                      \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout)
const int maxN = 100000 + 10;
using namespace std;
int n, m, s, t, l;
ll d[maxN];
vector<int> ke[maxN], idx[maxN], uv[maxN];
void dijkstra(int s)
{
    priority_queue<piii, vector<piii>, greater<piii>> pq;
    memset(d, 0x3f, sizeof d);
    pq.push({0, {s, 0}});
    d[s] = 0;
    while (!pq.empty())
    {
        ll dd = pq.top().fi;
        int u = pq.top().se.fi;
        int st = pq.top().se.se;
        pq.pop();
        if (dd != d[u])
            continue;
        // cout<<u<<endl;
        for (int i = 0; i < ke[u].size(); i++)
        {
            int v = ke[u][i];
            int nst = idx[u][i];
            ll c = uv[u][i];
            if (st)
                c += st * l + nst;
            if (d[v] > d[u] + c)
            {
                d[v] = d[u] + c;
                pq.push({d[v], {v, nst}});
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    file("METRO");
    cin >> n >> m >> s >> t >> l;
    for (int i = 1; i <= m; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        ke[u].push_back(v);
        idx[u].push_back(i);
        uv[u].push_back(c);
    }
    dijkstra(s);
    if (d[t] == d[0])
        d[t] = -1;
    cout << d[t];
    return 0;
}
