#include <bits/stdc++.h>
#define name "TASK"
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
const int N = 2e5 + 69;
using namespace std;
int n, m;
int up[N][30];
int h[N], f[N];
vector<pii> a[N];
void dfs(int u)
{
	for (auto it : a[u])
	{
		int v = it.fi, w = it.se;
		if (v == up[u][0])
			continue;

		h[v] = h[u] + 1;
		f[v] = f[u] + w;

		up[v][0] = u;
		for (int i = 1; i < 21; ++i)
			up[v][i] = up[up[v][i - 1]][i - 1];

		dfs(v);
	}
}
int lca(int u, int v)
{
	if (h[u] != h[v])
	{
		if (h[u] < h[v])
			swap(u, v);

		int k = h[u] - h[v];

		for (int i = 0; (1 << i) <= k; i++)
		{
			if (k >> i & 1)
				u = up[u][i];
		}
	}
	if (u == v)
		return u;

	for (int i = 20; i >= 0; i--)
	{
		if (up[u][i] != up[v][i])
		{
			u = up[u][i];
			v = up[v][i];
		}
	}
	return up[u][0];
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	if (fopen(name ".inp", "r"))
	{
		freopen(name ".inp", "r", stdin);
		freopen(name ".out", "w", stdout);
	}
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int u, v, c;
		cin >> u >> v >> c;
		a[u].push_back({v, c});
		a[v].push_back({u, c});
	}
	dfs(1);

	cout << lca(4, 5);
	return 0;
}