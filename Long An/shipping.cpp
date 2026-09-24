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
int n, m, q, shop;
struct Shop
{
    int u, sl, tien;
};
Shop a[maxN], b[maxN];
vector<int> g[maxN];
int f[maxN];
void bfs(int u)
{
    queue<int> q;
    for (int i = 1; i <= n; i++)
        f[i] = INF;
    q.push(u);
    f[u] = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto v : g[u])
            if (f[v] == INF)
            {
                f[v] = f[u] + 1;
                q.push(v);
            }
    }
}
int check(int T, ll tien, int sl)
{
    for (int i = 1; i <= shop; i++)
        if (f[a[i].u] <= T)
        {
            if (tien >= 1LL * a[i].tien * a[i].sl)
            {
                sl -= a[i].sl;
                tien -= 1LL * a[i].sl * a[i].tien;
                if (sl <= 0)
                    return 1;
            }
            else
            {
                sl -= tien / a[i].tien;
                if (sl <= 0)
                    return 1;
                else
                    break;
            }
        }
    return 0;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    cin >> shop;
    for (int i = 1; i <= shop; i++)
    {
        int u, sl, tien;
        cin >> u >> sl >> tien;
        a[i] = {u, sl, tien};
    }
    sort(a + 1, a + shop + 1, [&](Shop x, Shop y)
         { return x.tien < y.tien; });

    cin >> q;
    while (q--)
    {
        int u, sl;
        ll tien;
        cin >> u >> sl >> tien;
        bfs(u);
        int l = 0;
        int r = n - 1;
        int ans = -1;
        while (l <= r)
        {
            int mid = l + r >> 1;
            if (check(mid, tien, sl))
                ans = mid, r = mid - 1;
            else
                l = mid + 1;
        }
        cout << ans << " ";
    }   
    return 0;
}
