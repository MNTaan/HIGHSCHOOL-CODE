#include <bits/stdc++.h>
using namespace std;

int n, m, num[10005], low[10005],
    cnt = 0, connect[10005], numSCC = 0;
vector<int> a[10005], xet[10005], S;

void dfs(int u)
{
    low[u] = num[u] = cnt++;
    S.push_back(u);
    connect[u] = 1;
    for (int v : a[u])
    {
        if (num[v] == -1)
            dfs(v);
        if (connect[v])
            low[u] = min(low[u], low[v]);
    }

    if (num[u] == low[u])
    {
        numSCC++;
        while (1)
        {
            int v = S.back();
            S.pop_back();
            connect[v] = 0;
            if (u == v)
                break;
        }
    }
}
struct luu
{
    int u, v, c;
} z[1000000];
bool cmp(luu a, luu b)
{
    return a.c < b.c;
}
set<int> s;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> z[i].u >> z[i].v >> z[i].c;
    }

    fill(num + 1, num + n + 1, -1);
    fill(low + 1, low + n + 1, 0);
    fill(connect + 1, connect + n + 1, 0);
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= m; j++)
        {
                }
    }
    for (int u = 1; u <= n; u++)
        if (num[u] == -1)
            dfs(u);

    cout << numSCC;

    return 0;
}