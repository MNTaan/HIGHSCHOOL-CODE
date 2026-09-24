#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
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
const int maxN = 100000 + 10;
using namespace std;
struct node
{
    ll  r, h;
} a[maxN];
ll f[maxN];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    ll n;
    cin >> n;
    ll Max=0;
    memset(f,0,sizeof f);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].r >> a[i].h;
        Max=max(Max,a[i].r);
        // f[a[i].r]=a[i].h;
    }
    // cout<<1;
    f[a[1].r]=a[1].h;
    for (int i = 2; i <=n; i++)
    {
        for(int j=a[i].r;j<=Max;j++)
        {
            f[a[i].r]=max(f[a[i].r],f[j]+a[i].h);
        }
    }
    ll z=0;
    for(int i=1;i<=Max;i++)
        z=max(z,f[i]);
    cout<<z;
    return 0;
}
