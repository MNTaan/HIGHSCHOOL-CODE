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
const int maxM = 500000+10;
const int maxN=300000+10;
using namespace std;
ll n,m,vis[maxN];
pii a[maxM];
vector<ll> ke[maxN];
bool bfs()
{
    queue<ll> q;
    q.push(1);
    while(!q.empty())
    {
        ll u=q.front();
        q.pop();
        if(u==n)
            return true;
        for(auto v:ke[u])
            if(vis[v]==0)
            {
                vis[v]=1;
                q.push(v);
            }
    }
    return false;
}
bool check(ll mid)
{
    for(int i=1;i<=n;i++)
        ke[i].clear();
    for(int i=1;i<=mid;i++)
    {
        ke[a[i].fi].push_back(a[i].se);
    }
    memset(vis,0,sizeof vis);
    if(bfs())
        return true;
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
        cin>>a[i].fi>>a[i].se;
    ll l=1,r=m,kq=-1;
    while(l<=r)
    {
        ll mid=(l+r)/2;
        if(check(mid))
        {
            kq=mid;
            r=mid-1;
        }
        else
            l=mid+1;
    }
    cout<<kq;
    return 0;
}
