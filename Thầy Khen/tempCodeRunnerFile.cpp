#include <bits/stdc++.h>
#define ll long long
#define int long long
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
const int INF = 1e18;
const int MOD = 0;
using namespace std;
ll n;
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    cin >> n;
    priority_queue<ll, vector<ll>, greater<ll>> p;
    for (int i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        p.push(x);
    }
    ll ans=0;
    while (p.size() > 1)
    {
        ll x1 = p.top();
        p.pop();
        ll x2 = p.top();
        p.pop();
        p.push(x1 + x2);
        ans+=(x1+x2);
    }
    cout <<ans;
    return 0;
}
