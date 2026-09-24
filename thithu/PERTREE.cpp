#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define inf 1e18
#define FORf(i, a, b) for (ll i = a; i <= b; i++)
#define FORb(i, a, b) for (ll i = b; i >= a; i--)

const ll maxN = 5e3 + 7;
const ll MOD = 1e9 + 7;

ll n;
ll p[maxN], bonus[maxN], res[maxN];
ll par[maxN], high[maxN];
vector<ll> adj[maxN];

void dfs(ll from)
{
    for (auto to : adj[from])
        if (to != par[from])
        {
            par[to] = from;
            high[to] = high[from] + 1;
            dfs(to);
        }
}
bool dd[maxN], trace[maxN];
ll x[maxN];

void xuly()
{
    FORf(pos, 1, n) trace[pos] = false;
    ll tam = 0;
    FORf(pos, 1, n)
    {
        ll node = x[pos];
        if (node == 1 || trace[par[node]])
        {
            trace[node] = true;
        }
        else
            return;
    }

    FORf(pos, 1, n)
    {
        ll tg = bonus[pos];
        ll num = x[pos];
        res[num] += tg;
        if (res[num] >= MOD)
            res[num] -= MOD;
    }
}

void tryy(ll i)
{
    FORf(j, 1, n) if (!dd[j])
    {
        dd[j] = true;
        x[i] = j;
        if (i == n)
            xuly();
        else
            tryy(i + 1);
        dd[j] = false;
    }
}
void sub1()
{
    tryy(1);
    FORf(i, 1, n) cout << res[i] << " ";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen("pertree.inp", "r"))
    {
        freopen("pertree.inp", "r", stdin);
        freopen("pertree.out", "w", stdout);
    }
    else if (fopen("input.txt", "r"))
    {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }
    cin >> n;
    FORf(i, 1, n - 1)
    {
        cin >> p[i];
        par[i + 1] = p[i];
        adj[p[i]].pb(i + 1);
    }
    FORf(i, 1, n) cin >> bonus[i];
    dfs(1);
    sub1();
    return 0;
}
