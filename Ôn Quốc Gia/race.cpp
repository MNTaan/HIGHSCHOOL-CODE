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
int n,k,s,d[maxN],dd[maxN];
bool vis[maxN];
vector<pii> ke[1000000];
int bfs(int s)
{
    queue<int> q;
    q.push(s);
    d[s]=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(auto z:ke[u])
        {
            int v=z.fi;
            int c=z.se;
            if(d[v]>d[u]+1)
            {
                d[v]=d[u]+1;
                dd[v]=dd[u]+c;
                if(dd[v]==k)
                    return d[v];
                q.push(v);
            }
        }
    }
    return -1;

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    file("race");
    cin>>n>>k>>s;
    int m=n-1;
    for(int i=1;i<=m;i++)
    {
        int u,v,c;
        cin>>u>>v>>c;
        ke[u].push_back({v,c});
        ke[v].push_back({u,c});
    }
    memset(d,0x3f,sizeof d);
    memset(dd,0,sizeof dd);
    cout<<bfs(s);
    return 0;
}
