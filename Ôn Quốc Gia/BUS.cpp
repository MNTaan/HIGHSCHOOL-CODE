#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
typedef pair<ll, ll> ii;

ll n, m, s, t, d[200005],cnt;
vector<ii> kea[300005], keb[300005];
void dijkstra()
{
    priority_queue<ii, vector<ii>,greater<ii>> p;
    d[s] = 0;
    p.push({0, s});
    while (!p.empty())
    {
        ll dinh = p.top().second;
        ll maxc= p.top().first;
        p.pop();
        if(maxc>d[dinh])
            continue;
        for (auto x : kea[dinh])
        {
            if (d[x.first] > max(d[dinh], x.second))
            {
                d[x.first] = max(d[dinh], x.second);
                p.push({d[x.first], x.first});
            }
        }
    }
}
bool sub1() 
{
    return (cnt==0);
}
void sub2()
{
    
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n >> m >> s >> t;
    cnt=0;
    for (int i = 1; i <= m; i++)
    {
        ll w, u, v, c;
        cin >> w >> u >> v >> c;
        if (w == 1)
        {
            kea[u].push_back({v, c});
            kea[v].push_back({u, c});
        }
        else
        if(w==2)
        {
            keb[u].push_back({v, c});
            keb[v].push_back({u, c});
            cnt++;
        }
    }
    if(sub1())
    {
        memset(d,0x3f,sizeof d);
        dijkstra();
        cout << d[t];
    }
    else
    {
        if(n<=5000 && m<=5000)
        {
            sub2();
        }
    }
    return 0;
}
