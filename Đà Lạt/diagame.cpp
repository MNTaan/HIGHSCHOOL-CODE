#include <bits/stdc++.h>
#define ll long long
#define int long long
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
const int maxN = 1e3 + 10;
const int INF = 1e18;
const int MOD = 0;
using namespace std;
int n, m, a[maxN][maxN], Assigned[maxN * maxN];
vector<int> adj[maxN * maxN];
bool Visted[maxN * maxN];

bool visit(int u)
{
    if (Visted[u])
        return false;
    Visted[u] = true;
    for (int v : adj[u])
    {
        if (Assigned[v] == 0 || visit(Assigned[v]))
        {
            Assigned[v] = u;
            return true;
        }
    }
    return false;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];

    for (int i = 1; i <= n; i += 2)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i][j] == 1 || a[i][j] == 3)
                adj[(i - 1) * (m + 1) + j].push_back(i * (m + 1) + j + 1);
            if (a[i][j] == 2 || a[i][j] == 3)
                adj[(i - 1) * (m + 1) + j + 1].push_back(i * (m + 1) + j);
        }
    }
    for (int i = 2; i <= n; i += 2)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i][j] == 1 || a[i][j] == 3)
                adj[i * (m + 1) + j + 1].push_back((i - 1) * (m + 1) + j);
            if (a[i][j] == 2 || a[i][j] == 3)
                adj[i * (m + 1) + j].push_back((i - 1) * (m + 1) + j + 1);
        }
    }
    memset(Assigned, 0, sizeof Assigned);
    memset(Visted, false, sizeof Visted);
    int res = 0;

    for (int i = 0; i <= n; i += 2)
    {
        for (int j = 1; j <= m + 1; j++)
        {
            memset(Visted, false, sizeof Visted);
            res += visit(i * (m + 1) + j);
        }
    }
    cout << res;
    return 0;
}
