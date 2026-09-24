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
const int maxN = 1e6 + 10;
const int INF = 1e18;
const int MOD = 0;
using namespace std;
ll n, m, s;
pii a[maxN];
ll res[maxN];

struct Person
{
    int b, c, id;
    Person() : b(0), c(0) {}

    Person(int _b, int _c, int _id)
    {
        b = _b, c = _c, id = _id;
    }

    bool operator<(const Person &x) const
    {
        return b < x.b;
    }
} p[maxN];

struct ok
{
    int c, t, id;

    ok(int _c, int _t, int _id)
    {
        c = _c, t = _t, id = _id;
    }

    bool operator<(const ok &k) const
    {
        return c > k.c;
    }
};

bool check(int d)
{
    priority_queue<ok> q;
    int j = n + 1;
    int total = 0;
    vector<int> v;
    for (int i = m; i >= 1; i--)
    {
        while (j - 1 >= 1 && p[j - 1].b >= a[i].fi)
        {
            j--;
            q.push(ok(p[j].c, d, p[j].id));
        }
        if (!v.empty())
        {
            res[a[i].se] = v.back();
            v.pop_back();
            continue;
        }
        if (q.empty())
            return false;
        ok x = q.top();
        q.pop();
        if (total + x.c > s)
            return false;
        total += x.c;
        res[a[i].se] = x.id;
        x.t--;
        if (x.t > 0)
        {
            for (int k = 1; k <= x.t; k++)
                v.push_back(x.id);
        }
    }
    return true;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    ll sz, T;
    cin >> sz >> T;
    while (T--)
    {
        cin >> n >> m >> s;

        for (int i = 1; i <= m; i++)
        {
            cin >> a[i].fi;
            a[i].se = i;
        }

        sort(a + 1, a + 1 + m);

        for (int i = 1; i <= n; i++)
            cin >> p[i].b;

        for (int i = 1; i <= n; i++)
            cin >> p[i].c;

        for (int i = 1; i <= n; i++)
            p[i].id = i;

        sort(p + 1, p + 1 + n);

        int l = 0, r = m, ans = -1;

        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (check(mid))
            {
                r = mid - 1;
                ans = mid;
            }
            else
                l = mid + 1;
        }
        if (ans == -1)
            cout << "NO" << endl;
        else
        {
            cout << "YES" << endl;
            check(ans);
            for (int i = 1; i <= m; i++)
                cout << res[i] << " ";
            cout << endl;
        }
    }
    return 0;
}
