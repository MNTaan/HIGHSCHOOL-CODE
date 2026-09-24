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
const int maxN = 1e6 + 10;
const int INF = 1e18;
const int MOD = 0;
using namespace std;
int n, T;
pii a[maxN];
bool used[maxN];
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    cin >> n >> T;
    for (int i = 1; i <= n; i++)
    {
        int u, v;
        cin >> u >> v;
        a[i] = {u, v};
    }
    sort(a + 1, a + n + 1, greater<pii>());
    int ans = 0;
    // for(int i=1;i<=n;i++)
    //     cout<<a[i].fi<<" "<<a[i].se<<endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = a[i].se; j >= 0; j--)
        {
            if (used[j] == false && j <= T)
            {
                used[j] = true;
                ans += a[i].fi;
                // cout << a[i].fi << " " << j << endl;
                break;
            }
        }
    }
    cout << ans;
    return 0;
}
