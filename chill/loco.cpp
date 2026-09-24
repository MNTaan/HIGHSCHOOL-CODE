#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define endl "\n"
#define fi first
#define se second
#define pii pair<ll, ll>
#define file(name)                    \
    freopen(name ".inp", "r", stdin); \
    freopen(name ".out", "w", stdout);
#define fileTHHB                      \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout)
const int maxN = 100000 + 10;
using namespace std;
ll n, p;
ll a[maxN], b[maxN], c[maxN];
ll dpn[maxN], dpt[maxN];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    cin >> n >> p;
    fill(a + 1, a + n + 1, 0);
    fill(b + 1, b + n + 1, 0);
    fill(c + 1, c + n + 1, 0);
    fill(dpt + 1, dpt + n + 1, -1e9);
    fill(dpn + 1, dpn + n + 1, -1e9);
    dpt[0] = 0;
    dpn[0] = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= p; j++)
        {
            if (i - j >= 0)
            {
                dpt[i] = max(dpt[i], dpn[i - j] + b[i]);
                dpn[i] = max(dpn[i], max(dpt[i - j] + a[i], dpt[i - j] + c[i]));
            }
        }
    }
    cout << max(*max_element(dpt + 1, dpt + n + 1), *max_element(dpn + 1, dpn + n + 1));
    return 0;
}
