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
const int maxN = 1e6 + 10;
using namespace std;
ll n,m,a[1001][1001],d[maxN];
ll get(ll d[],int n)
{
    ll k,kq=0;
    for(int i=1;i<=n;i++)
    {
        ll pos_t=i,pos_p=i;
        ll st=0,sp=0;
        while(pos_t>=1 && d[pos_t]>=d[i])
        {
            pos_t--;
            st++;
        }
        while(pos_p<=n && d[pos_p]>=d[i])
        {
            pos_p++;
            sp++;
        }
        k=d[i]*(st+sp-1);
        kq=max(kq,k);
    }
    return kq;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>a[i][j];
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i][j]==0)
                d[i]=0;
            else
                d[i]++;
        }
        ans=max(ans,get(d,m));
    }
    cout<<ans;
    return 0;
}
