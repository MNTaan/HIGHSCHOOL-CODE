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
const int maxN = 2e6 + 10;
const int INF = 1e18;
const int MOD = 0;
using namespace std;
ll n, id[maxN], cnt;
char a[maxN];
bool check[maxN];
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] == 'T')
            id[++cnt] = i;
    }
    for (int i = 1; i <= n; i++)
        check[i] = false;
    for (int i = 1; i <= n; i += 2)
        if (a[i] == 'T')
            check[i] = true;
    ll tmp = 1;
    ll ans = 0;
    for (int i = 1; i <= n; i += 2)
        if (a[i] == 'F')
        {
            while (check[id[tmp]] == true)
                tmp++;
            swap(a[i], a[id[tmp]]);
            ans += abs(id[tmp] - i);
            check[id[tmp]] = true;
        }
    cout << ans;
    return 0;
}
