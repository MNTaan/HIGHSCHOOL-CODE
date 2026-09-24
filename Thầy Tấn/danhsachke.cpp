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
const int maxN = 1000 + 10;
using namespace std;
ll n,m;
vector<ll> adj[maxN];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        ll u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);

    }
    for(int i=1;i<=n;i++)
    {
        cout<<i<<" ";
        for(auto j: adj[i])
            cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}
