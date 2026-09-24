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
ll a[maxN];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    ll n, k;
    ll Max1 = 0, Max2 = 0, vt1 = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] > Max1)
            Max1 = a[i], vt1 = i;
    }
    for (int i = 1; i <= n; i++)
        if (a[i] > Max2 && i != vt1)
            Max2 = a[i];
    ll ans = 0;
    ll luu = Max1;
    if(n==1)
    {
        ll m = 0;  
        for (int i = 1; i <= k; i++)
        {
            if (m <= a[1])
                ans += (a[1] - m), m++;
        }
        cout << ans;
        return 0;
    }
    while (k--)
    {
        if (Max1 > Max2)
        {
            ans += Max1;
            // cout << ans << " " << Max1 << endl;
            Max1--;
        }
        else
        {
            ans += Max2;
            Max1 = luu;
            // cout << ans << " " << Max2 << endl;
        }
    }
    cout << ans;
    return 0;
}