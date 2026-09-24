#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("avx,avx2,fma")
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
int n, m, U, V, T, start;
int dd[10005], pre[10005];
vector<int> a[10005];
void DFS(int u, int d)
{
    int v;
    dd[u] = T;
    for (int i = 0; i < a[u].size(); ++i)
    {
        v = a[u][i];
        if (v == start && d == 4)
        {
            while (u != start)
            {
                cout << u << ' ';
                u = pre[u];
            }
            cout << start << ' ';
            exit(0);
        }
        else if (dd[v] != T && d < 4)
            pre[v] = u, DFS(v, d + 1);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    file("travel12");
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> U >> V;
        a[U].push_back(V);
        a[V].push_back(U);
    }
    for (int i = 1; i <= n; i++)
    {
        sort(a[i].begin(), a[i].end());
        a[i].resize(unique(a[i].begin(), a[i].end()) - a[i].begin());
    }
    for (int i = 1; i <= n; i++)
    {
        ++T;
        start = i;
        DFS(start, 1);
    }
    cout << -1;
    return 0;
}
