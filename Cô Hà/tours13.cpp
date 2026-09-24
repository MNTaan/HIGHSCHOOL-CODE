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
const int maxN = 1000 + 10;
using namespace std;
priority_queue<pii, vector<pii>, greater<pii>> p;
ll n, m, d[maxN];
vector<pii> ke[maxN];
int dijsktra(int s)
{
    bool check = true;
    p = priority_queue<pii, vector<pii>, greater<pii>>();
    memset(d, 0x3f, sizeof d);
    d[s] = 0;
    p.push({0, s});
    while (!p.empty())
    {
        int u = p.top().se;
        p.pop();
        if (u == s && d[u])
            return d[s];
        for (auto v : ke[u])
        {
            if (d[v.fi] > d[u] + v.se)
            {
                d[v.fi] = d[u] + v.se;
                p.push({d[v.fi], v.fi});
            }
        }
        if (u == s && check)
        {
            d[u] = 1e9;
            check = false;
        }
    }
    return -1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    file("tours13");
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            ke[i].clear();
        for (int i = 1; i <= m; i++)
        {
            int u, v, c;
            cin >> u >> v >> c;
            ke[u].push_back({v, c});
        }
        for (int i = 1; i <= n; i++)
            cout << dijsktra(i) << endl;
    }
    return 0;
}
