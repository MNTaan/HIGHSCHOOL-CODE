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
ll n;
bool dd[maxN];
set<ll> st;
void bfs(ll n)
{
    queue<ll> q;
    q.push(n);
    while (!q.empty())
    {
        ll u = q.front();
        q.pop();
        if (u == 0)
            continue;
        for (int i = 1; i * i <= u; i++)
        {
            if(u%i!=0)
                continue;
            ll x = i;
            ll y = 1ll * (u / x);
            if (x * y != u)
                continue;
            ll c = (x - 1) * (y + 1);
            if(dd[c])
                continue;
            dd[c]=true;
            // cout << x << " " << y << " " << c << endl;
            q.push(c);
            st.insert(c);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    ll dem = 0;
    cin >> n;
    fill(dd+1,dd+n+1,false);
    bfs(n);
    
    return 0;
}
