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
string n, m;
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    cin >> n >> m;
    ll sz = n.size();
    string msn = "";
    sz = m.size() - 1 - sz;
    for (int i = m.size() - 1; i > sz; i--)
        msn = m[i] + msn;
    ll cnt = 0;
    for (int i = 0; i <= sz; i++)
        cnt = cnt * 10 + (m[i] - '0');
    // cout << cnt;
    if (n > msn)
        cout << cnt;
    else
        cout << cnt + 1;

    return 0;
}
