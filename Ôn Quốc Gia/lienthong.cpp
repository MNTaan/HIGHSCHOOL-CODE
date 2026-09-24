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
const int maxN = 100000 + 10;
using namespace std;
ll n,m;
vector<ll> ke[maxN];
bool vis[maxN];
void dfs(int u)
{
    vis[u]=true;
    for(auto v:ke[u])
    {
        if(!vis[v])
        {
            vis[v]=true;
            dfs(v);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        ll u,v;
        cin>>u>>v;
        ke[u].push_back(v);
        ke[v].push_back(u);
    }
    memset(vis,false,sizeof vis);
    ll dem=0;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            dem++;
            dfs(i);
        }
    }
    cout<<dem;
    return 0;
}
