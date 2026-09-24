#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define p2l pair<ll, ll>
#define fi first
#define se second
#define inf 1e18
#define FORf(i, a, b) for (ll i = a; i <= b; i++)
#define FORb(i, a, b) for (ll i = b; i >= a; i--)
template <typename X, typename Y>
bool minimize(X &a, Y b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    else
        return false;
}
template <typename X, typename Y>
bool maximize(X &a, Y b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    else
        return false;
}
const ll maxN = 3e2 + 7;

ll n, m, q;
ll a[maxN], b[maxN];
struct point
{
    ll x, y;
};
vector<point> polygon[maxN];

namespace subtask1
{
    bool check()
    {
        FORf(i, 1, n)
        {
            if (polygon[i].size() != 4)
                return false;
            ll cnt = 0;
            for (auto pT : polygon[i])
                if (pT.y == 0)
                    cnt++;
            if (cnt < 2)
                return false;
        }
        return true;
    }
    void solve()
    {
        p2l posX[maxN];
        FORf(i, 1, n)
        {
            ll dem = 1;
            for (auto pT : polygon[i])
            {
                if (pT.y == 0)
                {
                    if (dem == 1)
                    {
                        posX[i].fi = pT.x;
                        dem++;
                    }
                    else
                    {
                        posX[i].se = pT.x;
                        break;
                    }
                }
            }
        }
        FORf(i, 1, n)
        {
            ll nu1 = min(posX[i].fi, posX[i].se);
            ll nu2 = max(posX[i].fi, posX[i].se);
            posX[i].fi = nu1;
            posX[i].se = nu2;
        }

        ll res = 0;
        FORf(i, 2, n)
        {
            ll tmp = posX[i].fi - posX[i - 1].se;
            if (tmp)
                res += tmp;
        }
        cout << res;
    }
}

namespace subtask23
{
    ll tam, res, dist[5444][5444];
    vector<p2l> adj[maxN];
    ll dd[maxN];
    vector<ll> path;
    void dfs(ll from)
    {
        for (auto varT : adj[from])
        {
            ll to = varT.fi;
            ll kc = varT.se;
            if (!dd[to])
            {
                dd[to] = true;
                path.pb(to);
                tam += kc;
                if (path.size() == n)
                    res = min(res, tam);
                else
                    dfs(to);
                path.pop_back();
                tam -= kc;
                dd[to] = false;
            }
        }
    }

    void solve()
    {
        FORf(i, 1, n)
        {
            FORf(j, 1, n) if (i != j)
            {
                ll len = inf;
                for (auto p1 : polygon[i])
                {
                    for (auto p2 : polygon[j])
                    {
                        ll cur_dist = sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
                        len = min(len, cur_dist);
                    }
                }
                dist[i][j] = len;
            }
        }

        FORf(i, 1, n)
            FORf(j, i + 1, n)
        {
            adj[i].pb({j, dist[i][j]});
            adj[j].pb({i, dist[i][j]});
        }

        res = inf;
        dd[1] = true;
        path.pb(1);
        dfs(1);
        cout << res;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen("task.inp", "r"))
    {
        freopen("task.inp", "r", stdin);
        freopen("task.out", "w", stdout);
    }
    else if (fopen("bal.inp", "r"))
    {
        freopen("bal.inp", "r", stdin);
        freopen("bal.out", "w", stdout);
    }

    cin >> n;
    FORf(i, 1, n)
    {
        cin >> m;
        FORf(j, 1, m)
        {
            ll x, y;
            cin >> x >> y;
            polygon[i].pb({x * 1000000, y * 1000000});
        }
    }

    if (subtask1::check())
        return subtask1::solve(), 0;
    return subtask23::solve(), 0;

    return 0;
}
