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
const int MOD = 0;
using namespace std;
vector<pii> st;
vector<pii> vec;
int a[10][10];

int HAU(int x, int y, int u, int v)
{
    if (x == u || y == v)
        return true;
    if (x - y == u - v)
        return true;
    if (x + y == u + v)
        return true;
    return false;
}

int XE(int x, int y, int u, int v)
{
    return (x == u || y == v);
}

int TUONG(int x, int y, int u, int v)
{
    if (x - y == u - v)
        return true;
    if (x + y == u + v)
        return true;
    return false;
}

int MA(int x, int y, int u, int v)
{
    int t1 = abs(x - u);
    int t2 = abs(y - v);
    return ((t1 == 1 && t2 == 2) || (t1 == 2 && t2 == 1));
}

int n = 8, m = 8, k;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    cin >> k;
    for (int i = 1; i <= k; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        x = 8 - x + 1;
        a[x][y] = w;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (a[i][j] == 0)
                st.pb({i, j});
            else
                vec.pb({i, j});

    int ans = 0, n = st.size();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (j != i)
                for (int t = 0; t < n; t++)
                    if (t != i && t != j)
                        for (int k = 0; k < n; k++)
                            if (k != i && k != j && k != t)
                            {
                                auto hau = st[i];
                                auto xe = st[j];
                                auto tuong = st[t];
                                auto ma = st[k];

                                int sum = 0;
                                for (auto it : vec)
                                {
                                    int u = it.first;
                                    int v = it.second;
                                    if (HAU(hau.fi, hau.se, u, v) || XE(xe.fi, xe.se, u, v) || TUONG(tuong.fi, tuong.se, u, v) || MA(ma.fi, ma.se, u, v))
                                    {
                                        sum += a[u][v];
                                    }
                                }

                                ans = max(ans, sum);
                            }
    cout << ans;
    return 0;
}
