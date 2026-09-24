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
const int maxN = 100 + 5;
using namespace std;
string s1, s2, hd;
string tong(string a, string b)
{
    while (a.size() < b.size())
        a = "0" + a;
    while (a.size() > b.size())
        b = "0" + b;
    ll nho = 0, dv = 0;
    string kq = "";
    for (int i = a.size() - 1; i >= 0; i--)
    {
        ll x = int(a[i] - '0') + int(b[i] - '0') + nho;
        dv = x % 10;
        nho = x / 10;
        kq = char(dv + '0') + kq;
    }
    if (nho > 0)
        kq = "1" + kq;
    return kq;
}
string f[maxN][maxN][3];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    cin >> hd;
    cin >> s1;
    cin >> s2;
    int n = s1.size(), m = hd.size();
    hd = "*" + hd;
    s1 = "*" + s1;
    s2 = "*" + s2;
    for (int i = 0; i <= m; i++)
    {
        f[i][0][1] = f[i][0][2] = "1";
    }

    for (int j = 1; j <= n; j++)
        for (int i = j; i >= 1; i--)
        {
            if (s1[j] == hd[i])
            {
                for (int k = j - 1; k >= i - 1; k--)
                {
                    f[i][j][1] = tong(f[i][j][1], f[i - 1][k][2]);
                }
            }
            if (s2[j] == hd[i])
            {
                for (int k = j - 1; k >= i - 1; k--)
                {
                    f[i][j][2] = tong(f[i][j][2], f[i - 1][k][1]);
                }
            }
        }
    string kq = "0";
    for (int i = m; i <= n; i++)
    {
        kq = tong(kq, f[m][i][1]);
        kq = tong(kq, f[m][i][2]);
    }
    cout << kq;
    return 0;
}
