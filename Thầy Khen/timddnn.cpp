#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define endl "\n"
#define fi first
#define se second
#define pii pair<ll, ll>
#define plll pair<ll, pii>
#define file(name)                    \
    freopen(name ".inp", "r", stdin); \
    freopen(name ".out", "w", stdout);
#define fileTHHB                      \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout)
const int maxN = 200000 + 10;
using namespace std;
ll n, m, x, y, z, t;
vector<pii> adj[maxN];
ll d[1001][1001], check[1001][1001];
ll dx[10] = {0, 1, -1, 0};
ll dy[10] = {1, 0, 0, -1};
void dijkstra(ll q, ll w)
{
    priority_queue<plll, vector<plll>, greater<plll>> p;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
            d[i][j] = 1e9;
    d[q][w] = 0;
    p.push({0, {q, w}});
    while (!p.empty())
    {
        plll x = p.top();
        p.pop();
        ll so = x.fi;
        pii px = x.se;
        for (int i = 0; i <= 3; i++)
        {
            ll a = px.fi + dx[i];
            ll b = px.se + dy[i];
            if (a < 0 || b < 0 || a >= n || b >= m)
                continue;
            if (check[a][b] == 0)
                continue;
            if (d[a][b] > d[px.fi][px.se] + 1)
            {
                d[a][b] = d[px.fi][px.se] + 1;
                p.push({d[a][b], {a, b}});
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    cin >> n >> m >> x >> y >> z >> t;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            ll k;
            cin >> k;
            check[i][j] = k;
            adj[i].pb({j, k});
            adj[j].pb({i, k});
        }
    }
    dijkstra(x, y);
    if (d[z][t] == 1e9)
        cout << -1;
    else
        cout << d[z][t];
    return 0;
}
