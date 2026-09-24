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
string tong(string a, string b)
{
    while (a.size() > b.size())
        b = "0" + b;
    while (a.size() < b.size())
        a = "0" + a;
    ll nho = 0;
    ll dv = 0;
    string ans = "";
    for (int i = a.size() - 1; i >= 0; i--)
    {
        ll x = (ll)(a[i] - '0') + (ll)(b[i] - '0') + nho;
        nho = x / 10;
        dv = x % 10;
        ans = char(dv + '0') + ans;
    }
    if (nho > 0)
        return "1" + ans;
    return ans;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    string a, b;
    cin >> a;
    cin >> b;
    cout << tong(a, b);
    return 0;
}
