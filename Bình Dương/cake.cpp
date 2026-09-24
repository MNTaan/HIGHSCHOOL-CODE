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
const int maxN = 2e5 + 50;
const int INF = 1e18;
const int MOD = 0;
using namespace std;
pii hero[maxN], mag[maxN];
int n, m, k, s, x;
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    cin >> n >> m >> k >> x >> s;
    for (int i = 1; i <= m; i++)
        cin >> mag[i].se;
    for (int i = 1; i <= m; i++)
        cin >> mag[i].fi;

    for (int i = 1; i <= k; i++)
        cin >> hero[i].se;
    for (int i = 1; i <= k; i++)
        cin >> hero[i].fi;

    sort(mag + 1, mag + m + 1);
    sort(hero + 1, hero + k + 1);

    for (int i = 2; i <= m; i++)
        mag[i].se = min(mag[i].se, mag[i - 1].se);

    for (int i = 2; i <= k; i++)
        hero[i].se = max(hero[i].se, hero[i - 1].se);

    int ans = n * x;

    for (int i = 1; i <= k; i++)
    {
        if (hero[i].fi > s)
            continue;

        ans = min(ans, (n - hero[i].se) * x);
    }

    for (int i = 1, j = k; mag[i].fi <= s && i <= m; i++)
    {
        while (j >= 1 && mag[i].fi + hero[j].fi > s)
            j--;

        if (j >= 1)
            ans = min(ans, (n - hero[j].se) * mag[i].se);
        else
            ans = min(ans, n * mag[i].se);
    }
    cout << ans;
    return 0;
}
