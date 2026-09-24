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
const int maxN = 100000 + 10;
const int INF = 1e18;
const int MOD = 0;
using namespace std;
ll d[maxN], c[maxN];
pii a[maxN];
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i].first >> a[i].second;
        ll l, p;
        cin >> l >> p;
        for (int i = 1; i <= n; i++)
            a[i].first = l - a[i].first;
        sort(a + 1, a + n + 1);
        a[0].first = 0;
        a[n + 1].first = l;
        ll dem = 0;
        ll z = 0;
        priority_queue<ll> q;
        if (p - l >= 0)
        {
            cout << 0 << endl;
        }
        else
        {
            for (int i = 0; i <= n; i++)
            {
                if (a[i + 1].first - a[i].first <= p)
                {
                    p = p - (a[i + 1].first - a[i].first);
                    q.push(a[i + 1].second);
                }
                else
                {
                    while (p < a[i + 1].first - a[i].first)
                    {
                        if (q.empty())
                        {
                            z++;
                            break;
                        }
                        dem++;
                        p = p + q.top();
                        q.pop();
                    }
                    if (z > 0)
                    {
                        dem = -1;
                        break;
                    }
                    p = p - (a[i + 1].first - a[i].first);
                    q.push(a[i + 1].second);
                }
            }
            cout << dem << endl;
        }
    }
    return 0;
}
