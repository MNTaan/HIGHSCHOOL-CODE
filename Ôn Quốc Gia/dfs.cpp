#include <bits/stdc++.h>
using namespace std;

int n, m, s, f;
bool a[10000][10000], visited[10000];
int trace[1005];
bool d[100000];

void DFS()
{
    stack<int> st;
    st.push(s);
    d[s] = true;
    while (!st.empty())
    {
        int u = st.top();
        st.pop();
        if (u == f)
            return;
        for (int v = 1; v <= n; v++)
        {
            if (a[u][v] && !d[v])
            {
                d[v] = true;
                trace[v] = u;
                st.push(v);
            }
        }
    }
}

int main()
{
    freopen("DFS.inp", "r", stdin);
    freopen("DFS.out", "w", stdout);
    memset(a, false, sizeof(a));
    cin >> n >> m >> s >> f;
    int u, v;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        a[u][v] = true;
        a[v][u] = true;
    }
    memset(d, false, sizeof(d));
    DFS();
    if (!d[f])
        cout << "FALSE" << endl;
    else
    {
        cout <<"TRUE" << endl;
    }
    return 0;
}
