#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define endl "\n"
#define fi first
#define se second
#define pii pair<ll, ll>
#define file(name)                         \
    if (fopen(name ".inp", "r"))           \
    {                                      \
        freopen(name ".inp", "r", stdin);  \
        freopen(name ".out", "w", stdout); \
    }
#define fileTHHB                            \
    if (fopen("input.txt", "r"))            \
    {                                       \
        freopen("input.txt", "r", stdin);   \
        freopen("output.txt", "w", stdout); \
    }
const int maxN = 5e3 + 10;
using namespace std;
ll a[maxN],b[maxN];
ll dp[maxN][maxN];
ll n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    cin>>n;
    ll Max=-1e9;
      for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) cin >> b[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dp[i][j]=max(a[i]*b[j]+dp[i-1][j-1],a[i]*b[j]);
            Max=max(dp[i][j],Max);
        }
    }
    cout << Max;
    return 0;
}
