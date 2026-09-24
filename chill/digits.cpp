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
const int maxN = 200000 + 10;
using namespace std;
ll n, k;
ll p[10];
vector<ll> v;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    file("digits");

    cin >> n >> k;
    p[0] = 1;
    for (int i = 1; i < 10; i++)
        p[i] = p[i - 1] * 10;
    string s;

    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        ll m = s.size() - 1;
        for (int j = 0; j <= m; j++)
        {
            ll t = (9 - (s[j] - 48)) * p[m - j];
            if (t > 0)
                v.pb(t);
        }
    }
    ll ans = 0;
    sort(v.begin(), v.end(), greater<ll>());
    if (k > v.size())
        k = v.size();
    for (int i = 0; i < k; i++)
        ans = v[i];
    cout << ans;
    return 0;
}
