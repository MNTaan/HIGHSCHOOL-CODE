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
const int N = 2e5 + 10;
const int INF = 1e18;
const int MOD = 0;
const int Block = 700;
using namespace std;
int n, m, x, y, z, q;
int a[N];
int in[N][2];
int out[N][2], sz[N], change[N];
vector<pii> g[N];
unordered_map<int, int> mp[N];
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    int cnt = 0;
    cin >> n >> m >> q;
    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y >> z;
        g[x].pb({y, z});
        g[y].pb({x, z});
        if (z == 1)
            cnt++;
        in[x][z]++;
        in[y][z]++;
    }
    for (int i = 1; i <= n; i++)
        sz[i] = g[i].size();
    for (int i = 1; i <= n; i++)
    {
        vector<pii> c;
        for (pii v : g[i])
        {
            if (sz[i] <= Block)
            {
                if (sz[v.fi] > Block || i < v.fi)
                    c.pb(v);
            }
            else if (sz[v.fi] > Block && i < v.fi)
                c.pb(v);
        }
        g[i] = c;
    }
    //	cout <<cnt<<endl;
    for (int i = 1; i <= q; i++)
    {
        int id;
        cin >> id;
        change[id]++;
        for (pii &v : g[id])
        {
            int p = (change[v.fi] - mp[id][v.fi]) & 1;
            mp[id][v.fi] = change[v.fi];
            if (p == 0)
            {
                in[v.fi][v.se]--;
                in[v.fi][!v.se]++;
                v.se = !v.se;
            }
            else
            {
                in[id][v.se]--;
                in[id][!v.se]++;
                in[v.fi][v.se]++;
                in[v.fi][!v.se]--;
            }
        }
        cnt = cnt - in[id][1] + in[id][0];
        swap(in[id][1], in[id][0]);
        cout << cnt << ' ';
    }
    return 0;
}
