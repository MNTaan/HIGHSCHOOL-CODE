#include <bits/stdc++.h>
#define ll long long
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
const int maxN = 1000 + 10;
using namespace std;
ll a[maxN], f[maxN][maxN];
double t;
ll n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    cin >> n >> t;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int d = 1; d <= n; d++)
    {
        for (int i = 1; i + d - 1 <= n; i++)
        {
            int j = i + d - 1;
            ll Max = -1e9, Min = 1e9;
            for (int z = i; z <= j; z++)
            {
                Max = max(Max, a[z]);
                Min = min(Min, a[z]);
            }
            double c = (double)(j - i + 1) / (double)(Max - Min + 1);
            if (c >= t)
                f[i][j] = 1;
            else
            {
                f[i][j] = 1e9;
                for (int z = i; z < j; z++)
                    f[i][j] = min(f[i][j],f[i][z]+f[z+1][j]);
            }
        }
    }
    cout<<f[1][n];
    return 0;
}
