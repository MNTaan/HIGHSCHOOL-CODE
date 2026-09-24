#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
ll n, m, d;
bool used[1000000], lie[1044122];
vector<ll> ke[100000];
void phantom(ll k)
{
    stack<ll> s;
    s.push(k);
    used[k] = true;
    while (!s.empty())
    {
        ll xx = s.top();
        used[xx] = true;
        s.pop();
        for (auto i : ke[xx])
            if (!used[i])
                s.push(i);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("ketban.inp", "r", stdin);
    freopen("ketban.out", "w", stdout);
    cin >> n;
    ll u, v;
    while (cin >> u >> v)
    {
        ke[u].push_back(v);
        ke[v].push_back(u);
    }
    d = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!used[i])
        {
            phantom(i);
            d++;
        }
        if (d > 1)
        {
            cout << "0";
            return 0;
        }
    }
    cout << "1";
    return 0;
}
