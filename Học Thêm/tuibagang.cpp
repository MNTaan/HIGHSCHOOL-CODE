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
const int maxN = 200000 + 10;
using namespace std;
ll a[maxN],b[maxN],f[1001][1001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    ll n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i]>>b[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(b[i]<=j)
                f[i][j]=max(f[i-1][j],f[i-1][j-b[i]]+a[i]);
            else
                f[i][j]=f[i-1][j];
        }
    }
    cout<<f[n][m];
    return 0;
}
