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
const int maxN = 305 + 10;
using namespace std;
int n, k;
int a[maxN];
long long f[maxN][maxN][maxN];
ll calc(int l, int r, int k)
{
    if (k == 0)
        return 0;
    if (l > r)
        return -1e15;
    long long &res = f[l][r][k];
    if (res != -1)
        return res;
    res = max(calc(l + 1, r, k), calc(l, r - 1, k));
    if (l <= r - 1)
    {
        res = max(res, calc(l, r - 2, k - 1) + abs(a[r] - a[r - 1]));
        res = max(res, calc(l + 2, r, k - 1) + abs(a[l] - a[l + 1]));
        res = max(res, calc(l + 1, r - 1, k - 1) + abs(a[l] - a[r]));
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    memset(f, 255, sizeof(f));
    cout << calc(1, n, k);
    return 0;
}
