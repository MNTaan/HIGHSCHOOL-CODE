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
const int maxN = 200000 + 10;
using namespace std;
ll n;
ll f[1000][1000];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    cin >> n;
    ll s = 0, smax = 0;
    for (int i = 1; i <= 600; i++)
    {
        for (int j = 1; j <= 600; j++)
            f[i][j] = 0;
    }
    ll x, y, r, c;

    for (int i = 1; i <= n; i++)
    {
        cin >> x >> y >> r >> c;
        for (int j = y; j <= y + c - 1; j++)
            for (int k = x; k <= r + x - 1; k++)
                f[j][k] = 1;
    }

    return 0;
}
