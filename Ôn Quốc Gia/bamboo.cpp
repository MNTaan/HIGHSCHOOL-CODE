#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i <= b; i++)
struct ii
{
    int x, y, dr;
    ii(int x, int y, int dr) : x(x), y(y), dr(dr) {}
};
int o1[4] = {0, 0, 1, -1};
int o2[4] = {1, -1, 0, 0};
int n, m;
vector<string> a;
vector<vector<int>> drl, drr, dcu, dcd;

void init()
{
    cin >> n >> m;
    a.resize(n);
    drl.assign(n + 2, vector<int>(m + 2));
    dcu = dcd = drr = drl;
    for (string &i : a)
        cin >> i;
    rep(i, 1, n)
        rep(j, 1, m) if (a[i - 1][j - 1] == '.')
            drl[i][j] = drl[i][j - 1] + 1;
    rep(i, 1, n) for (int j = m; j >= 1; j--) if (a[i - 1][j - 1] == '.')
        drr[i][j] = drr[i][j + 1] + 1;
    rep(j, 1, m) rep(i, 1, n) if (a[i - 1][j - 1] == '.')
        dcu[i][j] = dcu[i - 1][j] + 1;
    rep(j, 1, m) for (int i = n; i >= 1; i--) if (a[i - 1][j - 1] == '.')
        dcd[i][j] = dcd[i + 1][j] + 1;
}

bool kt(int u, int v, int d, int dr)
{
    if (!(u >= 1 && u <= n && v >= 1 && v <= m))
        return false;
    if (dr == 0)
        return d <= drl[u][v];
    if (dr == 1)
        return d <= drr[u][v];
    if (dr == 2)
        return d <= dcu[u][v];
    if (dr == 3)
        return d <= dcd[u][v];
}

bool bfs(int d)
{
    vector<vector<bool>> b[4];
    rep(i, 0, 3) b[i].assign(n + 1, vector<bool>(m + 1, true));
    queue<ii> q;
    rep(k, 2, 3) rep(i, 1, n) if (a[i - 1][0] == '.' && kt(i, 1, d, k)) q.push(ii(i, 1, k)), b[k][i][1] = false;
    while (q.size())
    {
        int u = q.front().x, v = q.front().y, t = q.front().dr;
        q.pop();
        if (t > 1 && v == m)
            return true;
        int tt = (t < 2) ? 0 : 2;
        rep(i, 0 + tt, 1 + tt)
        {
            int x = u + o1[i], y = v + o2[i];                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       
            if (kt(x, y, d, t) && b[t][x][y])                                   
            {
                b[t][x][y] = false;
                q.push(ii(x, y, t));
            }
        }
        rep(k, 0, 3) if (k != t)
        {
            if (kt(u, v, d, k) && b[k][u][v] == true)
                q.push(ii(u, v, k)), b[k][u][v] = false;
            int dd = d - 1, x = u + dd * o1[k], y = v + dd * o2[k];
            if (kt(x, y, d, k) && b[k][x][y] == true)
                q.push(ii(x, y, k)), b[k][x][y] = false;
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("BAMBOO.inp", "r", stdin);
    freopen("BAMBOO.out", "w", stdout);
    init();
    int l = 0, r = min(n, m);
    while (l <= r)
    {
        int m = (l + r) >> 1;
        if (bfs(m))
            l = m + 1;
        else
            r = m - 1;
    }
    cout << max(0, r);
    return 0;
}
