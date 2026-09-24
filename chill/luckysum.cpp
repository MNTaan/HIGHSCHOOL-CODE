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
const int maxN = 1e6 + 10;
using namespace std;
ll n;
queue<ll> q;
vector<ll> v;
queue<pair<ll, vector<ll>>> qq;
bool used[maxN];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    file("luckysum");
    cin >> n;
    if (n >= 4)
        q.push(4);
    if (n >= 7)
        q.push(7);
    while (!q.empty())
    {
        ll x = q.front();
        q.pop();
        v.pb(x);
        if (n >= x * 10 + 4)
            q.push(x * 10 + 4);
        if (n >= x * 10 + 7)
            q.push(x * 10 + 7);
    }
    // for(auto i:v)
    //     cout<<i<<" ";
    // cout<<endl;
    used[n] = true;
    vector<ll> vv;
    qq.push({n, vv});

    while (!qq.empty())
    {
        ll x = qq.front().fi;
        vector<ll> vt = qq.front().se;
        qq.pop();
    

        if (x == 0)
        {
            for (auto i : vt)
                cout << i << " ";
            return 0;
        }
        for (auto i : v)
        {
            if (x - i >= 0 && !used[x - i])
            {

                used[x - i] = true;
                vt.pb(i);
                qq.push({x - i, vt});
                // cout<<qq.front().fi<<endl;
                vt.pop_back();
            }
        }
    }
    cout << -1;
    return 0;
}
