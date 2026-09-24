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
const int maxN = 1e4 + 10;
const int INF = 1e18;
const int MOD = 0;
using namespace std;
ll n, a[maxN], t, m, b[maxN], A, B, par[maxN];
bool check[100005];
struct node
{
    ll u, v, w;
};
node edge[100005];
ll fpar(ll u)
{
    if (par[u] < 0)
        return u;
    par[u] = fpar(par[u]);
    return par[u];
}
bool ktra(ll u, ll v)
{
    u = fpar(u);
    v = fpar(v);
    if (u == v)
        return 0;
    if (par[u] > par[v])
        swap(u, v);
    par[u] += par[v];
    par[v] = u;
    return 1;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    file("aznet");
    cin >> t;
    while (t--)
    {
        A = B = 0;
        cin >> n >> m;
        memset(par, 255, sizeof(par));
        for (int i = 1; i < n; i++)
            cin >> a[i];
        for (int i = 1; i < n; i++)
            cin >> b[i];
        for (int i = 1; i <= m; i++)
            cin >> edge[i].u >> edge[i].v >> edge[i].w, check[i] = 0;
        for (int i = 1; i <= m; i++)
        {
            if (edge[i].w == 2)
                continue;
            A += ktra(edge[i].u, edge[i].v);
        }
        memset(par, 255, sizeof(par));
        for (int i = 1; i <= m; i++)
        {
            if (edge[i].w == 1)
                continue;
            B += ktra(edge[i].u, edge[i].v);
        }
        ll x = -1;
        ll temp = 2e9 + 7;
        ll Max = n - 1 - B;
        Max = max((ll)0, Max);
        for (int y = Max; y <= min(n - 1, A); y++)
        {
            if (temp > a[y] + b[n - 1 - y])
            {
                temp = a[y] + b[n - 1 - y];
                x = y;
            }
        }
        // cout << x << "\n";

        ll y = n - 1 - x;
        ll dem = 0;

        for (int i = 1; i <= m; i++)
        {
            if (edge[i].w == 2)
                continue;
            check[i] = ktra(edge[i].u, edge[i].v);
        }
        memset(par, 255, sizeof(par));
        dem = 0;
        for (int p = 1; p <= m; p++)
            if (check[p])
                dem += ktra(edge[p].u, edge[p].v);
        for (int i = 1; i <= m; i++)
        {
            if (dem >= x)
                break;
            if (edge[i].w == 2 || check[i])
                continue;
            check[i] = ktra(edge[i].u, edge[i].v);
            dem += check[i];
        }
        for (int i = 1; i <= m; i++)
        {
            if (edge[i].w == 1)
                continue;
            check[i] = ktra(edge[i].u, edge[i].v);
        }
        for (int i = 1; i <= m; i++)
            if (check[i])
                cout << i << " ";
        cout << "\n";
    }
    return 0;
}
