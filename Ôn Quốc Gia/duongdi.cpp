#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
//#define push_back pb;
using namespace std;
typedef pair<ll,ll> ii;
ll n,m,q,d[1000000],s1,s2,pi[100000];
vector<ii> ke[100000];
void dijkstra()
{
    priority_queue<ii,vector<ii>,greater<ii>> p;
    d[1]=0;
    p.push({d[1],1});
    while(!p.empty())
    {
        ll dinh=p.top().second;
        p.pop();
        for(auto x: ke[dinh])
        {
            if(d[x.first]>d[dinh]+x.second)
            {
                d[x.first]=d[dinh]+x.second;
                p.push({d[x.first],x.first});
            }
        }
    }

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("duongdi.inp","r",stdin);
    freopen("duongdi.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        ll u,v,c;
        cin>>u>>v>>c;
        ke[u].push_back({v,c});
        ke[v].push_back({u,c});
    }
    fill(d+1,d+n+1,1e18);
    dijkstra();
    cout<<d[n];
    return 0;
}
