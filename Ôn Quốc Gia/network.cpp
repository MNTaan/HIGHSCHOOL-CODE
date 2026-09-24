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
ll n,m,q,tp[maxN];
vector<ll> ke[maxN];
bool vis[maxN];
struct xay
{
    int u,v,c;
} a[maxN];
bool cmp(xay a,xay b)
{
    return a.c<b.c;
}
void dfs(int u,int vt)
{
    vis[u]=true;
    tp[u]=vt;
    for(auto v:ke[u])
    {
        if(!vis[v])
        {
            vis[v]=true;
            tp[v]=vt;
            dfs(v,vt);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // chua ra nha
    cin>>n>>m>>q;
    for(int i=1;i<=m;i++)
    {
        ll u,v;
        cin>>u>>v;
        ke[u].push_back(v);
        ke[v].push_back(u);
    }
    for(int i=1;i<=q;i++)
    {
        ll x,y,z;
        cin>>a[i].u>>a[i].v>>a[i].c;
    }
    sort(a+1,a+n+1,cmp);
    int vt=1;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            dfs(i,vt);
            ++vt;
        }
    }
    return 0;
}
