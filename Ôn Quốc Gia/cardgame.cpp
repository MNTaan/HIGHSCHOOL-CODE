#include <bits/stdc++.h>
#define ll long long
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
ll n, r[maxN], b[maxN];
struct cardgame
{
    int u, v, w;
};
vector<cardgame> a;
ll par[maxN], sz[maxN];
void makeset()
{
    for (int i = 1; i <= n; i++)
        par[i] = i, sz[i] = 1;
}
int find(int u)
{
    if (par[u] == u)
        return u;
    return par[u] = find(par[u]);
}
bool join(int u, int v)
{
    u = find(u);
    v = find(v);
    if (u == v)
        return false;
    if (sz[u] < sz[v])
        swap(u, v);
    par[v] = u;
    return true;
}
bool cmp(cardgame u, cardgame v)
{
    return u.w < v.w;
}
void kruskal()
{
    makeset();
    vector<cardgame> mst;
    int mst_weight = 0;
    int dem = 0;
    sort(a.begin(), a.end(), cmp);
    for (auto e : a)
    {
        if (dem == n - 1)
            break;
        if (join(e.u, e.v))
        {
            mst_weight += e.w;
            dem++;
        }
    }
    cout << mst_weight;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> r[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (int i = 1; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            cardgame e;
            e.u = i;
            e.v = j;
            e.w = min(r[i] ^ b[j], r[j] ^ b[i]);
            a.push_back(e);
        }
    }
    kruskal();
    return 0;
}
