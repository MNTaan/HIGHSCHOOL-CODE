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
const int maxN = 200000 + 10;
const int INF = 1e18;
const int MOD = 0;
using namespace std;
string st;
vector<ll> p, s;
ll n, l, r, mid, ans;
bool isValid(ll mid)
{
    ll r = 0;
    for (int l = 0; l < p.size(); l++)
    {
        ll tmp = p[l], l1 = s[r], r1 = s[r];
        while (r < s.size() && abs(l1 - tmp) <= mid && abs(r1 - tmp) + (r1 - l1) <= mid)
        {
            r1 = s[r];
            r++;
        }
    }
    return r == s.size();
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    file("packman");
    cin >> n >> st;
    for (int i = 0; i < st.size(); i++)
    {
        if (st[i] == 'P')
            p.pb(i);
        if (st[i] == '*')
            s.pb(i);
    }
    r = n - 1, ans = n - 1;
    while (l <= r)
    {
        mid = l + (r - l) / 2;
        if (isValid(mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    cout << ans;
    return 0;
}
