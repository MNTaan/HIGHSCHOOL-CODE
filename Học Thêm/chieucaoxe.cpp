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
const int maxN = 300005;
using namespace std;
ll n,m,s,t,d[maxN];
vector<pii> ke[maxN];   
void dijkstra()
{
    priority_queue<pii,vector<pii>> p;
    d[s]=1e8;
    p.push({d[s],s});
    while(!p.empty())
    {
        int u=p.top().se;
        p.pop();
        for(auto v:ke[u])
        {
            ll Min=min(d[u],v.se);
            if(d[v.fi]<Min)
            {   
                d[v.fi]=Min;
                p.push({d[v.fi],v.fi});
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    cin>>n>>m>>s>>t;
    for(int i=1;i<=m;i++)
    {
        ll u,v,c;
        cin>>u>>v>>c;
        ke[u].push_back({v,c});
        ke[v].push_back({u,c});
    }
    fill(d+1,d+n+1,-1e8);
    dijkstra();
    cout<<d[t];
    return 0;
}
