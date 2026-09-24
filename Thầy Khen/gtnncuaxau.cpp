#include <bits/stdc++.h>
#define ll long long
#define int long long
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
const int maxN = 1e5 + 10;
const int INF = 1e18;
const int MOD = 0;
using namespace std;
ll dem[maxN];
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    ll T;
    cin >> T;
    while (T--)
    {
        ll k;
        string s;
        memset(dem, 0, sizeof(dem));
        cin >> k;
        cin >> s;
        for (int i = 0; i < s.size(); i++)
            dem[s[i] - 'A']++;
        priority_queue<ll> p;
        for (int i = 0; i < 26; i++)
            p.push(dem[i]);
        while (k)
        {
            ll x = p.top();
            p.pop();
            p.push(x - 1);
            k--;
        }
        ll ans = 0;
        while (!p.empty())
        {
            ll x = p.top();
            p.pop();
            ans += x * x;
        }
        cout << ans << endl;
    }
    return 0;
}
