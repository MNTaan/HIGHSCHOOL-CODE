
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
ll n,a[maxN];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    ll ans=0;
    ll k;
    for(int i=1;i<=n;i++)
    {
        ll pos_t=i,pos_p=i;
        ll st=0,sp=0;
        while(pos_t>=1 && a[pos_t]>=a[i])
        {
            pos_t--;
            st++;
        }
        while(pos_p<=n && a[pos_p]>=a[i])
        {
            pos_p++;
            sp++;
        }
        k=a[i]*(st+sp-1);
        ans=max(ans,k);
    }
    cout<<ans;
    return 0;
}
