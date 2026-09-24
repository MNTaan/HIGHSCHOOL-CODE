#include <bits/stdc++.h>
#define ll long long
#define int long long
#define ld long double
#define pb push_back
#define endl "\n"
#define fi first
#define se second
#define pii pair<ll, ll>
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
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
const int maxN = 100100 + 10;
const int INF = 1e18;
const int MOD = 0;
using namespace std;
ll m, r, n, steps[maxN], sta[maxN], cnt[maxN];
ll res[maxN];
bool vis[maxN];
vector<ll> adj;
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    cin >> n >> r >> m;
    for (int i = 1; i <= m; i++)
    {
        ll x;
        cin >> x;
        steps[i] = (x % n + n) % n;
    }
    int pos = 0;
    for (int i = 1; i <= m; i++)

    {
        pos += steps[i];
        if (pos >= n)
            pos -= n;
        cnt[pos]++;
    }

    int sum = pos;
    pos = 0;
    while (!vis[pos])
    {
        vis[pos] = true;
        adj.push_back(pos);
        pos += sum;
        if (pos >= n)
            pos -= n;
    }

    for (int i : adj)
        sta[i] += r / adj.size();
    for (int i = 0; i < r % adj.size(); i++)
        sta[adj[i]]++;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            ll tmp = i + j;
            if (tmp >= n)
                tmp -= n;
            res[tmp] += 1LL * sta[i] * cnt[j];
        }
    res[0]++;

    for (int i = 0; i < n; i++)
        cout << res[i] << " ";
    cout << endl;

    return 0;
}
