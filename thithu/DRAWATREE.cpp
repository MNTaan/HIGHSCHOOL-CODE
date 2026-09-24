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
const int maxN = 200000 + 10;
const int INF = 1e18;
const int MOD = 1e9 + 22071997;
using namespace std;
int n;
bool a[5050][5050];
vector<pii> edges;
int result = 0;
bool isCrossing(int a, int b, int c, int d)
{
    if (a > b)
        swap(a, b);
    if (c > d)
        swap(c, d);
    return (a < c && c < b && b < d) || (c < a && a < d && d < b);
}
bool isValidTree(vector<pii> &tree)
{
    int m = tree.size();
    for (int i = 0; i < m; ++i)
    {
        for (int j = i + 1; j < m; ++j)
        {
            if (isCrossing(tree[i].fi, tree[i].se, tree[j].fi, tree[j].se))
                return false;
        }
    }
    return true;
}
void dfs(int idx, vector<pii> &currentTree, vector<bool> &visited)
{
    if (currentTree.size() == n - 1)
    {
        if (isValidTree(currentTree))
        {
            result = (result + 1) % MOD;
        }
        return;
    }

    for (int i = idx; i < edges.size(); ++i)
    {
        int u = edges[i].fi, v = edges[i].se;
        if (!visited[u] || !visited[v])
        {
            visited[u] = visited[v] = true;
            currentTree.pb(edges[i]);
            dfs(i + 1, currentTree, visited);
            currentTree.pop_back();
            visited[u] = visited[v] = false;
        }
    }
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    file("DRAWATREE");
    cin >> n;
    memset(a, false, sizeof(a));
    for (int i = 1; i < n; ++i)
    {
        string s;
        cin >> s;
        for (int j = 0; j < s.size(); ++j)
        {
            if (s[j] == 'N')
            {
                a[i][i + j + 1] = true;
                a[i + j + 1][i] = true;
            }
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = i + 1; j <= n; ++j)
        {
            if (!a[i][j])
            {
                edges.emplace_back(i, j);
            }
        }
    }

    vector<pii> currentTree;
    vector<bool> visited(n + 1, false);
    dfs(0, currentTree, visited);

    cout << result << endl;
    return 0;
}
