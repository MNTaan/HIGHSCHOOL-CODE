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
const int maxN = 100000 + 10;
using namespace std;
int n;
bool vis[maxN];
vector<int> aa,ba,ad,bd;
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    file("dancing");
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        if(x>0)
            ad.push_back(x);
        else
            aa.push_back(x);
    }
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        if(x>0)
            bd.push_back(x);
        else
            ba.push_back(x);
    }
    sort(aa.begin(),aa.end());
    sort(ba.begin(),ba.end());
    sort(ad.begin(),ad.end(),cmp);
    sort(bd.begin(),bd.end(),cmp);
    int dem=0;
    int vt1=0;
    int vt2=0;
    while(true)
    {
        if(vt1==ad.size() || vt2==ba.size())
            break;
        if(ad[vt1]+ba[vt2]<0)
        {
            vt1++;
            vt2++;
            dem++;
        }
        else
            vt1++;
    }
    vt1=0;
    vt2=0;
    while(1)
    {
        if(vt1==bd.size() || vt2==aa.size())
            break;
        if(bd[vt1]+aa[vt2]<0)
        {
            vt1++;
            vt2++;
            dem++;
        }
        else
            vt1++;
    }
    cout<<dem;
    return 0;
}
