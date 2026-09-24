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
const int maxN = 300000 + 10;
using namespace std;
ll d[maxN],n,a[maxN],b[maxN];
vector<ll> v;
bool check(int mid)
{
    int t = a[mid] + n;
    memset(b, 0, sizeof b);
    for (int i = 1; i <= n; i++)
        b[i] = a[i];
    for (int i = 1; i <mid; i++)
        b[i] += n - i;
    for (int i = mid + 1; i <= n; i++)
        b[i] += n - i +1 ;
    for (int i = 1; i <= n; i++)
        if (b[i] > t)
            return false;
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    file("familiar");
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    ll l=1,r=n,mid,ans;
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
    cout<<n-ans+1;
    return 0;
}
