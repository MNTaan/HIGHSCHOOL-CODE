#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define fi first
#define se second
#define pii pair<ll, ll>
#define pb push_back
#define file(name)                    \
    freopen(name ".inp", "r", stdin); \
    freopen(name ".out", "w", stdout);
#define fileTHHB                      \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout)
const int maxN = 200000 + 10;

using namespace std;
ll n,m,k,dem[maxN],ke[1001][1001],s,t;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    cin>>n>>m>>s>>t;
    for(int i=1;i<=m;i++)
    {
        ll u,v;
        cin>>u>>v;
        ke[u][v]=1;
        ke[v][u]=1;
    }
    if(ke[s][t]==1)
        cout<<"2 dinh vua nhap co canh noi";
    else
        cout<<"2 dinh vua nhap khong co canh noi";
    return 0;
}
