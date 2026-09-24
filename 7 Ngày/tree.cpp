#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dou double
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
const ll maxN = 3e5 + 7;
ll n, q, u, v;
ll a[maxN];
vector<ll> adj[maxN];
namespace subtask1
{
    ll ans;
    vector<ll> vec;
    bool dd[maxN];
    void dfs(ll from)
    {
        for (auto to : adj[from])
            if (!dd[to])
            {
                dd[to] = true;
                vec.pb(to);
                if (to == v)
                {
                    ll tmp = 1;
                    ll cur_len = 0;
                    FORf(pos, 1, vec.size() - 1)
                    {
                        if (tmp % 2 == 1)
                        {
                            if (a[vec[pos]] > a[vec[pos - 1]])
                                tmp++;
                            else
                            {
                                if (tmp > 1)
                                    cur_len += tmp - 1;
                                tmp = 1;
                            }
                        }
                        else
                        {
                            if (a[vec[pos]] < a[vec[pos - 1]])
                                tmp++;
                            else
                            {
                                if (tmp > 1)
                                    cur_len += tmp - 1;
                                tmp = 1;
                            }
                        }
                    }
                    if (tmp > 1)
                        cur_len += tmp - 1;
                    ans = max(ans, cur_len + 1);
                }
                dfs(to);
                vec.pop_back();
                dd[to] = false;
            }
    }
    void solve()
    {
        FORf(i, 1, q)
        {
            cin >> u >> v;
            ans = 0;
            vec.clear();
            vec.pb(u);
            dd[u] = true;
            dfs(u);
            dd[u] = false;
            cout << ans << '\n';
        }
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
    else if (fopen("tree.inp", "r"))
    {
        freopen("tree.inp", "r", stdin);
        freopen("tree.out", "w", stdout);
    }

    cin >> n >> q;
    FORf(i, 1, n) cin >> a[i];

    FORf(i, 1, n - 1)
    {
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    return subtask1::solve(), 0;

    return 0;
}
