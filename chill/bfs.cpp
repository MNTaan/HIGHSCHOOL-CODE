#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
ll n, m, s, t;
vector<ll> ke[100000];
ll d[100000]; // do dai duong di tu s toi v
void BFS()
{
    fill(d + 1, d + n + 1, 1e9);
    d[s] = 0;
    queue<ll> q;
    q.push(s);
    while (!q.empty())
    {
        ll u = q.front();
        q.pop();
        for (int i = 0; i < ke[u].size(); i++)
        {
            ll v = ke[u][i];
            if (d[v] > d[u] + 1)
            {
                d[v] = d[u] + 1;
                if (v == t)
                {
                    cout << "True";
                    return;
                }
                q.push(v);
            }
        }
    }
    cout << "False";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("bfs.txt", "r", stdin);
    freopen("bfs.txt", "w", stdout);
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; i++)
    {
        ll u, v;
        cin >> u >> v;
        ke[u].push_back(v);
        ke[v].push_back(u);
    }
    BFS();
    return 0;
}
