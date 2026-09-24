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
using namespace std;
const int N = 2e5 + 69;
int n;
vector<int> a[N];
int arr[N];
pii s1[N];
int s[3001][3001];
int x[N];
bool issub1()
{
    for (int i = 1; i < n; i++)
        if (s1[i].fi != i || s1[i].se != i + 1)
            return false;
    return true;
}
vector<int> path, paths;
void printPath(vector<int> stack)
{
    int i;
    for (i = 0; i < (int)stack.size() - 1;
         i++)
    {
        cout << stack[i] << " -> ";
    }
    cout << stack[i];
}
void DFS(vector<int> v[], bool vis[], int x, int y, vector<int> path)
{
    path.push_back(x);
    if (x == y)
    {
        paths = path;
        return;
    }
    vis[x] = true;

    if (!v[x].empty())
    {
        for (int j = 0; j < v[x].size(); j++)
        {
            if (vis[v[x][j]] == false)
                DFS(v, vis, v[x][j], y, path);
        }
    }

    path.pop_back();
}
void DFSCall(int x, int y, vector<int> v[], int n, vector<int> path)
{
    bool vis[n + 1];
    memset(vis, false, sizeof(vis));

    DFS(v, vis, x, y, path);
}
int mex(int u, int v)
{
    path.clear(), paths.clear();
    vector<int> ve;
    DFSCall(u, v, a, n, path);

    for (int i = 0; i < paths.size() - 1; i++)
        ve.pb(s[paths[i]][paths[i + 1]]);
    sort(ve.begin(), ve.end());
    int mex = 0;
    for (int i = 0; i < ve.size(); i++)
        if (ve[i] == mex)
            mex++;
    return mex;
}
int res = 0;
void pick()
{
    memset(s, 0, sizeof s);
    for (int i = 1; i < n; i++)
    {
        s[s1[i].fi][s1[i].se] = x[i - 1];
        s[s1[i].se][s1[i].fi] = x[i - 1];
    }

    int tmp = 0;
    for (int i = 1; i < n; i++)
        for (int j = i + 1; j <= n; j++)
        {
            tmp += mex(i, j);
        }
    res = max(res, tmp);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    cin >> n;
    int idx = 0;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
        s1[i] = {u, v};
    }
    if (issub1())
    {
        int res = 0;
        for (int i = 1; i <= n; i++)
        {
            int tmp = (i * (i + 1) / 2) * (n - i) + (n - i) * (n - i - 1) / 2;
            res = max(res, tmp);
        }
        cout << res;
    }
    else
    {
        for (int i = 0; i < n - 1; i++)
            x[i] = i;
        do
        {
            pick();
        } while (next_permutation(x, x + n - 1));

        cout << res;
    }
    return 0;
}
