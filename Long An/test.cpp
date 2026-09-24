#include <bits/stdc++.h>
#ifdef LOCAL
#include <cpp-dump/cpp-dump.hpp>
#define debug(...) cpp_dump(__VA_ARGS__)
#else
#define debug(...)
#endif // LOCAL
using namespace std;
#define ll long long
#define endl '\n'
#define all(v) (v).begin(), (v).end()
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define fileTHHB                            \
    if (fopen("input.txt", "r"))            \
    {                                       \
        freopen("input.txt", "r", stdin);   \
        freopen("output.txt", "w", stdout); \
    }
const int maxn = 5e5 + 50;
const int cs = 5e3 + 50;
const int INF = 1e9;
const ll LINF = 1e18;
int a[maxn];
vector<int> x;
vector<pii> p;
void Solve()
{
    int n, q;
    cin >> n >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= q; i++)
    {
        char c;
        int d;
        cin >> c >> d;
        if (c == '>' && d >= 0)
            x.pb(d);
        else if (c == '<' && d > 0)
        {
            x.pb(d - 1);
            x.pb(-1);
        }
        else if (c == '<' && d <= 0)
        {
            x.pb(-1);
            x.pb(-d);
            x.pb(-1);
        }
        else
        {
            x.pb(-1);
            x.pb(-d - 1);
        }
    }
    int num = 0;
    while (!x.empty())
    {
        if (x.back() == -1)
            num ^= 1;
        else if (p.empty() || x.back() < p.back().first)
            p.pb({x.back(), num});
        x.pop_back();
    }
    sort(all(p));
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == 0)
        {
            cout << 0 << ' ';
            continue;
        }
        int pos = lower_bound(all(p), make_pair(abs(a[i]), -1)) - p.begin();
        int c = (a[i] < 0);
        if (pos == 0)
            c ^= num;
        else
            c = p[pos - 1].se ^ 1;
        if (c)
            cout << -abs(a[i]) << ' ';
        else
            cout << abs(a[i]) << ' ';
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    fileTHHB;
    int T = 1;
    while (T--)
        Solve();
    return 0;
}