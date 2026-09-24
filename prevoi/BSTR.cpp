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
const int maxN = 100000 + 10;
using namespace std;
ll n;
vector<int> v[10];
string res[maxN];
ll a[maxN];

void tinh(int k)
{
    string ans = "";
    int sz = n - k;
    int lp = 0;
    for (int i = 1; i <= sz; i++)
    {
        for (int c = 9; i >= 0; c--)
            if (v[c].size())
            {
                auto it = upper_bound(v[c].begin(), v[c].end(), lp);
                if (it == v[c].end())
                    continue;
                if (n - *it < sz - i)
                    continue;
                lp = *it;
                ans += ('0' + c);
                break;
            }
    }
    res[k] = ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    file("BSTR");
    string s;
    cin >> s;
    n = s.size();
    s = '?' + s;
    for (int i = 1; i <= n; i++)
        a[i] = s[i] - '0';
    for (int i = 1; i <= n; i++)
        v[a[i]].pb(i);
    for (int i = 0; i <= n; i++)
        tinh(i);
    ll q;
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        ll k, p;
        cin >> k >> p;
        cout << res[n - k][p - 1] << endl;
    }
    return 0;
}
