#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define fi first
#define se second
#define pii pair<int, int>
#define file(name)                    \
    freopen(name ".inp", "r", stdin); \
    freopen(name ".out", "w", stdout);
#define fileTHHB                      \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout)
const int maxN = 5000 + 10;
const int maxM = 100000 + 10;
using namespace std;
int n, m, k,A,B,a[maxN],d[maxN],d2[maxN];
vector<pii> ke[maxN];
void dijkstra(ll s)
{
    priority_queue<pii, vector<pii>, greater<pii>> p;
    d[s] = 0;
    p.push({d[s], s});
    while (!p.empty())
    {
        ll u = p.top().se;
        p.pop();
        for (auto v : ke[u])
        {
            if (d[v.fi] > d[u] + v.se)
            {
                d[v.fi] = d[u] + v.se;
                p.push({d[v.fi], v.fi});
            }
        }
    }
}
void dijkstra2(ll s)
{
    priority_queue<pii, vector<pii>, greater<pii>> p;
    d2[s] = 0;
    p.push({d2[s], s});
    while (!p.empty())
    {
        ll u = p.top().se;
        p.pop();
        for (auto v : ke[u])
        {
            if (d2[v.fi] > d2[u] + v.se)
            {
                d2[v.fi] = d2[u] + v.se;
                p.push({d2[v.fi], v.fi});
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
    cin >> n >> m >> k;
    cin >> A >> B;
    for (int i = 1; i <= k;i++)
    {
        int u, z;
        cin >> u >> z;
        a[u] = z;
    }
    for (int i = 1;i<=m;i++)
    {
        int u,v,c;
        cin >> u >> v >> c;
        ke[u].push_back({v, c});
        ke[v].push_back({u, c});
    }
    fill(d + 1, d + n + 1, 1e9);
    fill(d2 + 1, d2 + n + 1, 1e9);
    dijkstra(A);
    dijkstra2(B);
    int Min = 1e18,vt;
    for (int i = 1; i <= n;i++)
    {
        if(a[i]>0)
        {
            Min = min(Min, d[i] + a[i] + d2[i]);
            if (Min == d[i] + a[i] + d2[i])
                vt = i;
        }
    }
    cout << Min << " " << vt;
    return 0;
}
