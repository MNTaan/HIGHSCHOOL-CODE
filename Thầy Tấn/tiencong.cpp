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
const int maxN = 2000 + 10;
const int INF = 1e18;
const int MOD = 0;
using namespace std;

int Adj[maxN][maxN];

int match(int n, int m, int K)
{
    vector<int> Mx(n + 1, 0);
    vector<int> My(m + 1, 0);
    vector<int> visit(n + 1, 0);
    vector<int> trace(n + 1);
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        if (Mx[i] == 0)
        {
            pair<int, int> edge = {0, 0};
            queue<int> q;
            q.push(i);
            visit[i] = i;
            while (!q.empty())
            {
                int u = q.front();
                q.pop();
                for (int v = 1; v <= n; v++)
                {
                    if (Adj[u][v] <= K)
                    {
                        if (My[v] == 0)
                        {
                            edge = {u, v};
                            break;
                        }
                        else
                        {
                            if (My[v] > 0 && visit[My[v]] != i)
                            {
                                q.push(My[v]);
                                visit[My[v]] = i;
                                trace[My[v]] = u;
                            }
                        }
                    }
                }
                if (edge.first > 0)
                    break;
            }
            if (edge.first > 0)
            {
                cnt++;
                while (true)
                {
                    int vPre = Mx[edge.first];
                    Mx[edge.first] = edge.second;
                    My[edge.second] = edge.first;
                    if (edge.first == i)
                        break;
                    edge = {trace[edge.first], vPre};
                }
            }
        }
    return cnt;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    file("tiencong");
    int n, K;
    cin >> n >> K;
    int w;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> w;
            Adj[i][j] = w;
        }

    int ans = match(n, n, K);

    cout << ans;
    return 0;
}
