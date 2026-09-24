#include <bits/stdc++.h>
#define ll long long
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
const int maxN = 50 + 5;
using namespace std;
ll a[maxN];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    ll n;
    cin >> n;
    ll sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    sort(a + 1, a + n + 1);
    ll ans = 0;
    ll luu = sum;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] <= 9)
        {
            sum -= a[i];
            sum += 9;
        }
        else
        {
            if (a[i] >= 90)
            {
                sum -= a[i];
                sum += 99;
            }
            else
            {
                sum -= a[i];
                sum += (90 + a[i] % 10);
            }
        }
        ans = max(ans, sum);
        sum = luu;
    }
    cout << ans;
    return 0;
}
