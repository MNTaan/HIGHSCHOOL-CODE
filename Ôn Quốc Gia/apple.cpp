#include <bits/stdc++.h>
#define ll long long
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
pii tg[10],tao[maxN];
double dttg(double xa, double ya, double xb, double yb, double xc, double yc)
{
    return 0.5 * abs(xa * yb - xb * ya + xb * yc - xc * yb + xc*ya-xa*yc);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    int n;
    for (int i = 1; i <= 3; i++)
        cin >> tg[i].x >> tg[i].y;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>tao[i].x>>tao[i].y;
    tg[4].x = tg[1].x;
    tg[4].y = tg[1].y;
    double s=dttg(tg[1].x,tg[1].y,tg[2].x,tg[2].y,tg[3].x,tg[3].y);
    ll dem=0;
    cout<<fixed<<setprecision(1)<<s<<endl;
    for(int i=1;i<=n;i++)
    {
        double dt1=dttg(tao[i].x,tao[i].y,tg[1].x,tg[1].y,tg[2].x,tg[2].y);
        double dt2=dttg(tao[i].x,tao[i].y,tg[1].x,tg[1].y,tg[3].x,tg[3].y);
        double dt3=dttg(tao[i].x,tao[i].y,tg[2].x,tg[2].y,tg[3].x,tg[3].y);
        if(s-(dt1+dt2+dt3)==0)
            dem++;
    }
    cout<<dem;
    return 0;
}
