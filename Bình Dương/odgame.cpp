#include <bits/stdc++.h>
#define ll long long
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
const int maxN = 200000 + 10;
using namespace std;
ll n, m;
map<pii, pii> p;
pii getSet(const pii &u)
{
    if (p.count(u) == 0)
        return p[u] = u;
    return u == p[u] ? u : p[u] = getSet(p[u]);
}
void joint(const pii u, const pii v)
{
    pii a = getSet(u), b = getSet(v);
    p[a] = b;
}
bool check(int u)
{
    return getSet({u, 0}) != getSet({u, 1});
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        string t;
        cin >> u >> v >> t;
        --u;
        if (t == "odd")
        {
            joint({u, 0}, {v, 1});
            joint({u, 1}, {v, 0});
        }
        else
        {
            joint({u, 0}, {v, 0});
            joint({u, 1}, {v, 1});
        }
        if (!check(u) || !check(v))
        {
            cout << i << endl;
            return 0;
        }
    }
    cout << m << endl;
    return 0;
}
