#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
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
const int maxN = 10000 + 10;
using namespace std;
ll n, m, s, d[maxN], f[maxN];
vector<ll> ke[maxN];
map<pii, bool> mp;
void bfs(ll s)
{
    queue<ll> q;
    fill(d + 1, d + n + 1, 1e18);
    fill(f + 1, f + n + 1, 0);
    d[s] = 0;
    q.push(s);
    f[s] = 1;
    while (!q.empty())
    {
        ll u = q.front();
        q.pop();
        for (auto v : ke[u])
        {
            if (f[v] == 0)
            {
                d[v] = d[u] + 1;
                f[v] = f[u];
                q.push(v);
            }
            else
            {
                if (d[v] == d[u] + 1)
                {
                    if (f[v] == 1)
                        f[v] = 2;
                }
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    file("stable");
    cin >> n >> m >> s;
    for (int i = 1; i <= m; i++)
    {
        ll u, v;
        cin >> u >> v;
        if (mp[{u, v}])
            continue;
        mp[{u, v}] = true;
        ke[u].pb(v);
    }
    bfs(s);
    ll dem = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i == s)
            continue;
        if (f[i] > 1)
            dem++;
    }
    cout << dem;
    return 0;
}
