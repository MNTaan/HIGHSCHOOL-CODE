#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pii pair<ll, ll>
const int maxN = 1e6;
using namespace std;

ll n, m;
ll ha, sa, hb, sb;
vector<ll> dha, dsa, dhb, dsb;
vector<pii> ke[maxN];

void dijkstra(ll k, vector<ll> &d)
{
    priority_queue< pii , vector<pii> , greater<pii> > pq;
    for (int i = 1; i <= n; i++)
    {
        d[i] = 2e9;
    }
    d[k] = 0;

    pq.push(make_pair(d[k], k));
    while (!pq.empty())
    {
        ll u_v = pq.top().first;
        ll u = pq.top().second;
        pq.pop();
        for (int i = 0; i < ke[u].size(); i++)
        {
            pair<ll, ll> x = ke[u][i];
            if (u_v + x.se < d[x.fi])
            {
                d[x.fi] = u_v + x.se;
                pq.push(make_pair(d[x.fi], x.fi));
            }
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("friend.inp", "r", stdin);
    freopen("friend.out", "w", stdout);
    dha.resize(maxN);
    dsa.resize(maxN);
    dhb.resize(maxN);
    dsb.resize(maxN);
    cin >> n >> m;
    cin >> ha >> sa >> hb >> sb;
    for (int i = 1; i <= m; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        ke[u].push_back(make_pair(v, c));
        ke[v].push_back(make_pair(u, c));
    }
    dijkstra(ha, dha);
    dijkstra(sa, dsa);
    dijkstra(hb, dhb);
    dijkstra(sb, dsb);

    ll tt = dha[sa];
    ll tm = dhb[sb];
    bool ok = false;
    ll vt, tg = 2e9;
    for (int i = 1; i <= n; i++)
    {
        if (dha[i] == dhb[i] && dha[i] + dsa[i] == tt && dhb[i] + dsb[i] == tm)
        {
            ok = true;
            if (dha[i] < tg)
            {
                tg = dha[i];
                vt = i;
            }
        }
    }
    if (ok)
    {
        cout << "YES" << endl;
        cout << tt << endl;
        cout << tm << endl;
        cout << vt << endl;
        cout << tg << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}
