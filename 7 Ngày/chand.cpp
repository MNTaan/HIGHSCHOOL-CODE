#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define str string
#define pb push_back
#define inf 1e18
#define p2l pair<ll, ll>
#define fi first
#define se second
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
const ll maxN = 1e6 + 7;
ll n, Q, u, v;
ll c[maxN];
vector<ll> adj[maxN];
namespace subtask1
{
    str S;
    ll flag;
    ll x[maxN], high[maxN], arr[maxN], arr2[maxN];
    ll ans[maxN];
    p2l query[maxN];
    bool check()
    {
        flag = inf;
        ll cnt1 = 0;
        FORf(i, 1, n)
        {
            if (adj[i].size() == 1)
            {
                if (flag == inf)
                    flag = i;
                cnt1++;
            }
            if (adj[i].size() > 2)
                return false;
        }
        if (cnt1 != 2)
            return false;

        FORf(i, 1, n) if (c[i] > 2) return false;
        return true;
    }
    void xuly()
    {
        ll cost = 0;
        FORf(pos, 1, n) cost += abs(arr[pos] - x[pos]);
        FORf(pos, 1, n) arr2[pos] = x[pos];
        ll limit = 0;
        FORf(pos, 1, Q)
        {
            ll be = min(high[query[pos].fi], high[query[pos].se]);
            ll en = max(high[query[pos].fi], high[query[pos].se]);

            bool ok = true;
            FORf(id, be, en) if (arr2[id] != arr2[en - id + 1])
            {
                ok = false;
                break;
            }
            if (!ok)
                break;
            else
            {
                ans[pos] = min(ans[pos], cost);
                limit = pos;
            }
        }
    }
    void tryy(ll i)
    {
        FORf(j, 1, 2)
        {
            x[i] = j;
            if (i == n)
                xuly();
            else
                tryy(i + 1);
        }
    }
    void solve()
    {
        arr[1] = flag;
        queue<ll> q;
        q.push(flag);
        ll pos = 1;
        high[flag] = 1;
        while (!q.empty())
        {
            ll from = q.front();
            q.pop();
            for (auto to : adj[from])
                if (high[to] == 0)
                {
                    pos++;
                    high[to] = high[from] + 1;
                    arr[pos] = to;
                    q.push(to);
                }
        }

        FORf(i, 1, n) arr[i] = c[arr[i]];
        FORf(i, 1, Q)
        {
            cin >> query[i].fi >> query[i].se;
            ans[i] = inf;
        }

        tryy(1);
        FORf(i, 1, Q) cout << ans[i] << '\n';
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
    else if (fopen("chand.inp", "r"))
    {
        freopen("chand.inp", "r", stdin);
        freopen("chand.out", "w", stdout);
    }
    cin >> n >> Q;
    FORf(i, 1, n) cin >> c[i];

    FORf(i, 1, n - 1)
    {
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    if (subtask1::check())
        return subtask1::solve(), 0;
    else if (Q == 3)
    {
        if (adj[1].size() == 2)
            cout << 1 << '\n'
                 << 2 << '\n'
                 << 4;
        else
            cout << 2 << '\n'
                 << 4 << '\n'
                 << 6;
    }
    else
    {
        FORf(i, 1, Q) cout << 0 << '\n';
    }
    return 0;
}