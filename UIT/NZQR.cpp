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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    string p = "NZQR";
    ll t_minus[4] = {1, 1, 2, 3};
    ll t_div[4] = {2, 2, 2, 3};
    char c1,c2,c3,ans;
    cin>>c1>>c2>>c3;
    ll t1=p.find(c1);
    ll t2=p.find(c3);
    ll tm=max(t1,t2);
    ll t;
    if(c2=='+')
        t=tm;
    if(c2=='-')
        t=t_minus[tm];
    if(c2=='*')
        t=tm;
    if(c2=='/')
        t=t_div[tm];
    cout<<p[t];
    return 0;
}
