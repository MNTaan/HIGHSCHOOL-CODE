#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back 
#define endl "\n"
#define x first
#define y second
#define pii pair<double, double>
#define file(name)                    \
    freopen(name ".inp", "r", stdin); \
    freopen(name ".out", "w", stdout);
#define fileTHHB                      \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout)
const int maxN = 1000 + 10;
using namespace std;
pii a[maxN];
double tinh(pii a,pii b)
{
    return (double)sqrt((b.x-a.x)*(b.x-a.x)+(b.y-a.y)*(b.y-a.y));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    double n,kc=1e9;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i].x>>a[i].y;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i!=j)
            {
                kc=min(kc,tinh(a[i],a[j]));
            }
        }
    }
    cout<<fixed<<setprecision(6)<<kc;
    return 0;
}
