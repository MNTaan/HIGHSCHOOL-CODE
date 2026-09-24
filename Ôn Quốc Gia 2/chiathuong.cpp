#include <bits/stdc++.h>
#define ll long long

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
const int maxN = 1000 + 10;
const int INF = 1e18;
const int MOD = 0;
using namespace std;
string dp[maxN][maxN];
string tong(string a, string b)
{
    int du = 0;
    int mid = 0;
    string res = "";
    a.insert(0, max(0, (int)(b.length() - a.length())), '0');
    b.insert(0, max(0, (int)(a.length() - b.length())), '0');
    for (int i = a.length() - 1; i >= 0; --i)
    {
        mid = ((int)a[i] - 48) + ((int)b[i] - 48) + du;
        du = mid / 10;
        res = (char)(mid % 10 + 48) + res;
    }
    if (du > 0)
        res = "1" + res;
    return res;
}
string chiathuong(ll m, ll n)
{
    if (dp[m][n] != "-1")
        return dp[m][n];
    if (m == 0 || m == 1 || n == 1)
        return dp[m][n] = "1";
    if (n == 0)
        return dp[m][n] = "0";
    if (m < n)
        return dp[m][n] = chiathuong(m, m);
    return dp[m][n] = tong(chiathuong(m, n - 1), chiathuong(m - n, n));
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    ll m, n;
    cin >> m >> n;
    for (int i = 0; i <= m + 1; i++)
        for (int j = 0; j <= n + 1; j++)
            dp[i][j] = "-1";

    cout << chiathuong(m, n);

    return 0;
}
