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
int n,c[10100],t[10100],l[10100],r[10100];
bool check(int T)
{
    for(int i=1;i<=n;i++)
        l[i]=r[i]=0;
    for(int i=0;i<n;i++)
        l[max(1,c[i]-T/t[i])]++, r[min(n,c[i]+T/t[i])]++;
    for(int i=1;i<=n;i++)
    {
        l[i]+=l[i-1];
        r[i]+=r[i-1];
        if(l[i]<i || r[i]>i)
            return false;
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    file("MOVE");
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>c[i]>>t[i];
    int l=0,r=100000000,ans=r;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(check(mid))
        {
            ans=mid;
            r=mid-1;
        }
        else
            l=mid+1;
    }
    cout<<ans<<endl;
    return 0;
}
