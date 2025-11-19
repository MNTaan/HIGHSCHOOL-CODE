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
vector<ll> v1;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    ll n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        v1.push_back(x);
    }
    for (int i = 1; i <= q; i++)
    {
        ll so, x, y;
        cin >> so >> x >> y;
        if (so == 1)
        {
            x--;
            if (x == v1.size())
                v1.push_back(y);
            else
            {
                vector<ll> v2;
                for (int i = 0; i < x; i++)
                    v2.pb(v1[i]);
                v2.pb(y);
                for (int i = x; i < v1.size(); i++)
                    v2.pb(v1[i]);
                v1 = v2;
                // for(int i=0;i<v1.size();i++)
                //     cout<<v1[i]<<" ";
                // cout<<endl;
            }
        }
        else
        {
            x--;
            y--;
            ll Max = 0;
            for (int i = x; i <= y; i++)
            {
                Max = max(Max, v1[i]);
            }
            cout << Max << endl;
        }
    }
    return 0;
}
