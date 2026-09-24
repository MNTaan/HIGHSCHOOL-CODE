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
const int maxN = 5e4 + 5 + 10;
const int INF = 1e18;
const int MOD = 0;
using namespace std;
int n, m;

struct bus
{
    ll id, a, b;
    bool operator<(const bus &other) const
    {
        if (a == other.a)
            return b < other.b;
        return a < other.a;
    }
};
bus c[maxN];
bool check(int pos)
{
    priority_queue<int> pq;
    for (int i = 1, j = 1; i <= m; i++)
    {
        while (j <= n && c[j].a <= i)
        {
            if (c[j].id <= pos)
                pq.push(-c[j].b);
            j++;
        }
        if (pq.empty())
            continue;
        if (-pq.top() < i)
            return false;
        pq.pop();
    }
    return pq.empty();
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    file("queue");
    cin >> m >> n;
    for (int i = 1; i <= n; i++)
    {
        ll a, b;
        cin >> a >> b;
        c[i] = {i, a, b};
    }
    sort(c + 1, c + 1 + n);

    int ans = 0;
    for (int l = 1, h = n; l <= h;)
    {
        ll mi = (l + h) / 2;
        if (check(mi))
        {
            ans = mi;
            l = mi + 1;
        }
        else
            h = mi - 1;
    }
    cout << ans << endl;
    return 0;
}
