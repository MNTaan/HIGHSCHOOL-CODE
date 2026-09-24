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
const int maxN = 200000 + 10;
using namespace std;
pii p[4];
pii calc(pii p1, pii p2, pii p3)
{
    pii p4;
    p4.fi = p1.fi ^ p2.fi ^ p3.fi;
    p4.se = p1.se ^ p2.se ^ p3.se;
    return p4;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    
    for (int i = 1; i <= 3; i++)
        cin >> p[i].fi >> p[i].se;
    pii tim=calc(p[1],p[2],p[3]);
    cout<<tim.fi<<" "<<tim.se;
    return 0;
}
