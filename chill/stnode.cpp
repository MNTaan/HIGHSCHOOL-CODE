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
const int maxN = 1e4 + 10;
using namespace std;
vector<int> find_path(int s, int t, const vector<vector<ll>> &ke)
{
    int n = ke.size();
    vector<int> trace(n, -1);
    queue<int> q;
    q.push(s);
    trace[s] = s;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : ke[u])
            if (trace[v] < 0)
            {
                q.push(v);
                trace[v] = u;
            }
    }

    vector<int> path;
    int u = t;
    while (u != s)
    {
        path.push_back(u);
        u = trace[u];
    }
    path.push_back(s);
    for (int i = 0, j = path.size() - 1; i < j; i++, j--)
        swap(path[i], path[j]);
    return path;
}

int bfs(int s, const vector<int> &pos, const vector<vector<ll>> &ke, vector<bool> &visited)
{
    queue<int> q;
    q.push(s);
    visited[s] = true;
    int r = -1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : ke[u])
            if (!visited[v] && pos[v] < 0)
            {
                q.push(v);
                visited[v] = true;
            }
            else
                r = max(r, pos[v]);
    }
    return r;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    s--, t--;
    vector<vector<ll>> ke(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        ke[u - 1].push_back(v - 1);
    }

    vector<int> path = find_path(s, t, ke);

    vector<int> pos(n, -1);
    for (int i = 0; i < (int)path.size(); i++)
    {
        pos[path[i]] = i;
    }

    vector<bool> visited(n, false);
    int r = -1, res = 0;
    for (int u : path)
    {

        if (u != s && u != t && r <= pos[u])
            res++;

        r = max(r, bfs(u, pos, ke, visited));
    }
    cout << res;
    return 0;
}
