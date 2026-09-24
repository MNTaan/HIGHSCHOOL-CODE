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
const int maxN = 1000 + 10;
using namespace std;
ll n, k;
ll a[maxN];
int ok(int i, int j, int len)
{
    int mid = (i + j) / 2;
    return (a[j] - a[i] <= 2 * len && a[mid] - a[i] <= len && a[j] - a[mid] <= len);
}
bool check(ll mid)
{
    int cnt = 0;
    int i = 1;
    while (i <= n)
    {
        int j = i;
        while (j <= n && ok(i, j + 1, mid))
            ++j;
        ++cnt;
        i = j + 1;
    }
    return cnt <= k;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    ll l = 0, r = 1e9, ans = 0;
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        if (check(mid))
        {
            r = mid - 1;
            ans = mid;
        }
        else
            l = mid + 1;
    }
    cout << ans;
    return 0;
}
