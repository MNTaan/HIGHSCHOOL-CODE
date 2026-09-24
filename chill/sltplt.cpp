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
const int maxN = 200000 + 10;
using namespace std;
ll n, m;
ll a[1000][1000];
vector<ll> b[maxN];
bool vis[maxN];
int cnt[maxN];
void dfs(ll u, ll &dem)
{
    vis[u] = true;
    cnt[dem]++;
    for (auto v : b[u])
    {
        if (vis[v] == false)
        {
            dfs(v, dem);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    ll T;
    cin >> T;
    while (T--)
    {
        cin >> n >> m;
        memset(a, 0, sizeof a);
        memset(vis, false, sizeof vis);
        memset(cnt, 0, sizeof cnt);
        ll dem = 0;
        for (int i = 1; i <= n; i++)
            b[i].clear();
        for (int i = 1; i <= m; i++)
        {
            ll u, v;
            cin >> u >> v;
            a[u][v] = a[v][u] = 1;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i == j)
                    continue;
                if (a[i][j] == 0 || a[j][i] == 0)
                {
                    b[i].pb(j);
                    b[j].pb(i);
                }
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (vis[i] == false)
            {
                dem++;
                dfs(i, dem);
            }
        }
        cout << dem << endl;
        sort(cnt + 1, cnt + dem + 1);
        for (int i = 1; i <= dem; i++)
            cout << cnt[i] << " ";
        cout << endl;
    }
    return 0;
}
