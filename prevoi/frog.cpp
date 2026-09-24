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
ll n, k;
ll p1[maxN], p2[maxN], f[201][201][201];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    file("frog");
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> p1[i];
    for (int i = 1; i <= n; i++)
        cin >> p2[i];
    memset(f, -0x3f, sizeof f);
    f[1][1][0] = p1[1] + p2[1];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            ll s = abs(i - j);
            if (s > k)
                continue;
            for (int z = i + 1; z <= n; z++)
            {
                if (j < i)
                {
                    if (s + abs(z - i) <= k)
                        f[z][j][abs(z - j)] = max(f[z][j][abs(z - j)], f[i][j][s] + p1[z]);
                }
                else if (abs(z - j) <= k)
                    f[z][j][abs(z - j)] = max(f[z][j][abs(z - j)], f[i][j][s] + p1[z]);
            }
            for (int z = j + 1; z <= n; z++)
            {
                if (i < j)
                {
                    if (s + abs(z - j) <= k)
                        f[i][z][abs(z - i)] = max(f[i][z][abs(z - i)], f[i][j][s] + p2[z]);
                }
                else if (abs(z - i) <= k)
                    f[i][z][abs(z - i)] = max(f[i][z][abs(z - i)], f[i][j][s] + p2[z]);
            }
        }
    cout << f[n][n][0];
    return 0;
}
