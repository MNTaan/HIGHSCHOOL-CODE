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
set<ll> z;
ll n,a[maxN],t[maxN],v[maxN];
bool check(int k)
{
    memset(v, 0x3f, sizeof v);
    memset(t, 0, sizeof t);
    for (int i = 1; i <= k; i++)
    {
        v[1000 + a[i]] = 0;
        t[1000 + a[i]]++;
    }
    for (int i = 2; i <= n - k + 1; i++)
    {
        t[1000 + a[i - 1]]--;
        t[1000 + a[i + k - 1]]++;
        if (t[1000 + a[i - 1]] == 0)
            v[1000 + a[i - 1]]++;
    }
    for (auto c : z)
    {
        if (v[1000 + c] == 0)
            return true;
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    file("rannum");
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        z.insert(a[i]);
    }    
    int l=1,r=n,kq;
    while(l<=r)
    {
        int mid=(l+r)/2;
        // cout<<mid;
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
