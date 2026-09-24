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
const int maxN = 5e3 + 10;
const int INF = 1e18;
const int MOD = 0;
using namespace std;
string s, t;
vector<int> x, y;
int n, m, X[maxN], Y[maxN], f[maxN][maxN], pos[maxN][30], c[30], p[maxN];
void preprocessString(const string &str, vector<int> &vec, int *arr)
{
    for (int i = 1; i <= str.size();)
    {
        if (isalpha(str[i]))
        {
            vec.push_back(str[i] - 'a');
            int j = i + 1;
            ll sum = 0;
            while (isdigit(str[j]) && j <= str.size())
            {
                sum = sum * 10 + (str[j++] - '0');
            }
            i = j;
            arr[vec.size() - 1] = sum;
        }
        else
        {
            i++;
        }
    }
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    cin >> s >> t;
    s = 'N' + s;
    t = 'I' + t;
    n = s.size() - 1;
    m = t.size() - 1;
    x.push_back('G');
    y.push_back('A');
    preprocessString(s, x, X);
    preprocessString(t, y, Y);

    n = x.size() - 1;
    m = y.size() - 1;

    for (int i = 1; i <= m; i++)
    {
        pos[++c[y[i]]][y[i]] = i;
        p[i] = c[y[i]];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            if (x[i] == y[j])
            {
                int u = p[j], cA = 0, cB = Y[j];
                for (int k = i; k >= 1; --k)
                {
                    if (x[k] == x[i])
                        cA += X[k];
                    while (u >= 1 && cB < cA)
                    {
                        f[i][j] = max(f[i][j], f[k - 1][pos[u][y[j]] - 1] + min(cA, cB));
                        --u;
                        cB += Y[pos[u][y[j]]];
                    }
                    f[i][j] = max(f[i][j], f[k - 1][pos[u][y[j]] - 1] + min(cA, cB));
                }
            }
        }
    }

    cout << f[n][m] << '\n';

    memset(f, 0, sizeof(f));
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (x[i] == y[j])
            {
                f[i][j] = (X[i] == Y[j] ? f[i - 1][j - 1] : 0) + min(X[i], Y[j]);
                ans = max(ans, f[i - 1][j - 1] + min(X[i], Y[j]));
            }
        }
    }
    cout << ans;
    return 0;
}
