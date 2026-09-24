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
vector<pii> v;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    ll a, b;
    cin >> a >> b;
    ll i = 1;
    while (i < 50 && (a != 0 && b != 0))
    {
        if (a == 0 || b == 0)
            break;
        if (a > b)
        {
            ll k = -a / b;
            v.pb({1, k});
            a = a + b * k;
        }
        else
        {
            int k = -b / a;
            v.pb({2, k});
            b = b + a * k;
        }
        i++;
    }
    cout << v.size() << endl;
    for (auto x : v)
        cout << x.fi << " " << x.se << endl;
    return 0;
}
