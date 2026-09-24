#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define fi first
#define se second
#define ii pair<ll, ll>
#define file(name)                    \
    freopen(name ".inp", "r", stdin); \
    freopen(name ".out", "w", stdout);
#define fileTHHB                      \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout)
const int maxN = 1e6;
using namespace std;
ll m, n, d[1001][1001], a[1001][1001];
ii ke[5];
void dijsktra()
{
    priority_queue<ii, vector<ii>> p;
    d[1][1] = a[1][1];
    p.push({1, 1});
    while (!p.empty())
    {
        ll u = p.top().first;
        ll v = p.top().second;
        p.pop();
        for (ll i = 0; i < 4; i++)
        {
            ll u2 = u + ke[i].first;
            ll v2 = v + ke[i].second;
            if (d[u2][v2] > d[u][v] + a[u2][v2] && u2 <= m && v2 <= n)
            {
                d[u2][v2] = d[u][v] + a[u2][v2];
                p.push({u2, v2});
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    ll t;
    cin >> t;
    while (t--)
    {
        cin >> m >> n;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cin >> a[i][j];
                d[i][j] = 1e18;
            }
        }
        ll k, f, t;
        cin >> k >> f >> t;
        ke[0] = {0, 1};
        ke[1] = {0, -1};
        ke[2] = {1, 0};
        ke[3] = {-1, 0};
        dijsktra();
        if (d[k][f] <= t)
            cout << "YES" << endl
                 << t - d[k][f] << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
