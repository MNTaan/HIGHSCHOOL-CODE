#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define fi first
#define se second
#define pii pair<ll, ll>
#define pb push_back
#define file(name)                    \
    freopen(name ".inp", "r", stdin); \
    freopen(name ".out", "w", stdout);
#define fileTHHB                      \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout)
const int maxN = 200000 + 10;

using namespace std;
ll n,m,k,dem[maxN];
vector<ll> ke[maxN];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        ll u,v;
        cin>>u>>v;
        ke[u].pb(v);
        ke[v].pb(u);
        dem[u]++;
        dem[v]++;
    }
    for(int i=1;i<=n;i++)
        if(dem[i]==k)
            cout<<i<<" ";
    return 0;
}
