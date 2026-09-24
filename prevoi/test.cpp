#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
ll t, n, a[1000000], dem;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--)
    {
        dem = 0;
        memset(a, 0, sizeof(a));
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int u = 1; u <= n - 2; u++)
        {
            for (int x = u + 1; x <= n - 1; x++)
            {
                ll av = 2 * a[x] - a[u];
                ll k = lower_bound(a + x + 1, a + n + 1, av) - a;
                ll l = upper_bound(a + x + 1, a + n + 1, av) - a;
                dem = dem + (l - k);
            }
        }
        cout << dem << endl;
    }
    return 0;
}
