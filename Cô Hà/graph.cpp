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
int n, m, num[10005], low[10005], cnt = 0, connect[10005], strong = 0;
vector<int> ke[10005], s;

void dfs(int u)
{
    low[u] = num[u] = cnt++;
    s.push_back(u);
    connect[u] = 1;
    for (int v : ke[u])
    {
        if (num[v] == -1)
            dfs(v);
        if (connect[v])
            low[u] = min(low[u], low[v]);
    }

    if (num[u] == low[u])
    {
        strong++;
        while (true)
        {
            int v = s.back();
            s.pop_back();
            connect[v] = 0;
            if (u == v)
                break;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    file("GRAPH");
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        ke[u].push_back(v);
    }

    memset(num, -1, sizeof num);
    memset(low, 0, sizeof low);
    memset(connect, 0, sizeof connect);
    for (int i = 1; i <= n; i++)
        if (num[i] == -1)
            dfs(i);
    cout << strong;
    return 0;
}
