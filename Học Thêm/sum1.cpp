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
const int maxN = 15000 + 10;
using namespace std;
ll n;
vector<ll> a;
ll search(vector<ll> a, ll n, ll k)
{
    ll l = 0;
    ll r = n - 1;
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        if (a[mid] == k)
            return mid;
        if (a[mid] < k)
            l = mid + 1;
        else if (a[mid] > k)
            r = mid - 1;
    }
    return r + 1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    file("sum1");
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    double ans = 0;
    while (a.size() > 2)
    {
        ll k = a[0] + a[1];
        ans += (k * .05);
        a.erase(a.begin(), a.begin() + 2);
        a.insert(a.begin() + search(a, a.size(), k), k);
    }
    ans = ans + (a[0] + a[1]) * 0.05;
    cout << fixed << setprecision(2) << ans;
    return 0;
}
