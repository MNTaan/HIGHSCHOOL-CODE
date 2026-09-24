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
bool ok = true, used[maxN];
int trace[maxN], h[maxN];
vector<int> adj[maxN];
void DFS(int u)
{
    used[u] = true;
    for (auto v : adj[u])
    {
        if (!used[v])
        {
            h[v] = h[u] + 1;
            trace[v] = u;
            DFS(v);
        }

        if (abs(h[v] - h[u]) + 1 == 4 && ok)
        {
            if (h[u] > h[v])
                swap(u, v);
            ok = false;
            cout << v << " " << trace[v] << " " << trace[trace[v]] << " " << u;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(1);
    return 0;
}
