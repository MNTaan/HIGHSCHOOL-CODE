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
const int maxN = 300000 + 300;
const int INF = 1e18;
const int MOD = 0;
using namespace std;

struct Person
{
    int limit, cost, id;
    Person()
    {
        limit = cost = id = 0;
    }
    bool operator<(const Person &p) const
    {
        return limit > p.limit;
    }
} who[maxN];
int m, n, s;
pii p[maxN];
int res[maxN];
bool check(int x)
{
    priority_queue<pii, vector<pii>, greater<pii>> q;

    int sumCost = s;

    int j = 1;
    for (int i = 1; i <= m; i += x)
    {
        while (j <= n && who[j].limit >= p[i].fi)
        {
            q.push({who[j].cost, who[j].id});
            j++;
        }

        if (q.empty())
            return false;

        if (sumCost < q.top().fi)
            return false;
        sumCost -= q.top().fi;
        int id = q.top().se;
        q.pop();

        for (int k = i; k <= i + x - 1; i++)
            res[p[k].se] = id;
    }

    return true;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    ll s, T;
    cin >> s >> T;
    while (T--)
    {
        cin >> n >> m >> s;
        for (int i = 1; i <= m; i++)
        {
            cin >> p[i].fi;
            p[i].se = i;
        }
        for (int i = 1; i <= n; i++)
            cin >> who[i].limit;
        for (int i = 1; i <= n; i++)
            cin >> who[i].cost;
        for (int i = 1; i <= n; i++)
            who[i].id = i;
        sort(who + 1, who + n + 1);
        sort(p + 1, p + m + 1, greater<pii>());
        if (!check(m))
        {
            cout << "NO" << endl;
            continue;
        }

        int L = 1, R = m;
        while (L < R)
        {
            if (R - L == 1)
            {
                if (check(L))
                    R = L;
                else
                    L = R;
            }
            else
            {
                int M = (L + R) >> 1;
                if (check(M))
                    R = M;
                else
                    L = M + 1;
            }
        }

        check(L);

        cout << "YES";
        for (int i = 1; i <= m; i++)
            cout << res[i] << endl;
    }
    return 0;
}
