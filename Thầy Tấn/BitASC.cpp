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
ll n, a[maxN];
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    file("bitasc");
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<int> b(n + 1, INT_MAX);
    b[0] = -1e9;
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        int k = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
        b[k] = a[i];
        res = max(res, k);
    }
    cout << res;
    return 0;
}
