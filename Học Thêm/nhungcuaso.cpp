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
const int maxN = 100 + 10;
using namespace std;
struct window
{
    int u,v,x,y;
} a[maxN];
int n,dd[maxN],dem,vet[maxN];
vector<int> ke[maxN];
bool de(int i,int j)
{
    return (a[j].u>=a[i].u && a[j].u<=a[i].x) && (a[j].y>=a[i].v && a[j].y<=a[i].y);
}
void dfs(int u)
{
    dd[u]=1;
    for(auto v:ke[u])
    {
        if(dd[v]==0)
            dfs(v);
    }
    vet[++dem]=u;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].u>>a[i].v>>a[i].x>>a[i].y;
        for(int j=1;j<i;j++)
        {
            if(de(i,j))
                ke[j].push_back(i);
        }
    }
    dfs(1);
    cout<<dem<<endl;
    for(int i=1;i<=dem;i++)
        cout<<vet[i]<<" ";
    return 0;
}
