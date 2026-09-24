#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define endl "\n"
#define x first
#define y second
#define pii pair<ll, ll>
#define file(name)                    \
    freopen(name ".inp", "r", stdin); \
    freopen(name ".out", "w", stdout);
#define fileTHHB                      \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout)
const int maxN = 200000 + 10;
using namespace std;
ll n, dem, d[1001][1001], dmin[maxN];
pii a[maxN];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].x >> a[i].y;
    memset(dmin, 0x3f, sizeof dmin);
    for (int i = 1; i <=n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(i==j)
                continue;
            d[i][j] = abs(a[i].x - a[j].x) + abs(a[i].y - a[j].y);
            dmin[i] = min(dmin[i], d[i][j]);
        }
    }
    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=1;j<=n;j++)
    //     {
    //         if(i==j)
    //             continue;
    //         cout<<d[i][j]<<endl;
    //     }
    // }
    // for(int i=1;i<=n;i++)
    //     cout<<dmin[i]<<endl;
    for (int i = 1; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            for (int k = j+1; k <= n; k++)
                if (d[i][j] == d[j][k] && d[j][k] == d[i][k] && d[i][k] == dmin[i] && dmin[i] == dmin[j] && dmin[j] == dmin[k])
                {
                    dem++;
                    // cout<<i<<" "<<j<<" "<<k<<endl;
                    // cout<<d[i][j]<<" "<<d[j][k]<<" "<<d[i][k]<<endl;
                }    
    cout<<dem;
    return 0;
}
