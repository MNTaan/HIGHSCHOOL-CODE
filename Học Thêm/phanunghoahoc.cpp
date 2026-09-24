#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define endl "\n"
#define fi first
#define se second
#define pii pair<ll, ll>
#define file(name)                    \
    freopen(name ".inp", "r", stdin); \
    freopen(name ".out", "w", stdout);
#define fileTHHB                      \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout)
const int maxN = 1e5 + 10;
using namespace std;
pair<string, string> p[maxN];
set<string> st;
vector<string> vs;
vector<int> ke[maxN];
int d[maxN];
int s, t;
int bfs(int s, int t)
{
    memset(d, 0x3f, sizeof d);
    d[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto v : ke[u])
        {
            if (d[v] > d[u] + 1)
            {
                d[v] = d[u] + 1;
                q.push(v);
            }
            if (v == t)
                return d[t];
        }
    }
    return -1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    ll n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string s1, s, s2;
        cin >> p[i].fi >> s >> p[i].se;
        st.insert(p[i].fi);
        st.insert(p[i].se);
    }
    string x, y;
    cin >> x >> y;
    vs.push_back("?");
    for (auto c : st)
        vs.push_back(c);
    for (int i = 0; i < vs.size(); i++)
        if (vs[i] == x)
        {
            s = i;
            break;
        }
    for (int i = 0; i < vs.size(); i++)
        if (vs[i] == y)
        {
            t = i;
            break;
        }
    for (int i = 1; i <= n; i++)
    {
        ll u, v;
        for (int j = 0; j < vs.size(); j++)
            if (vs[j] == p[i].fi)
            {
                u = j;
                break;
            }
        for (int j = 0; j < vs.size(); j++)
            if (vs[j] == p[i].se)
            {
                v = j;
                break;
            }
        ke[u].push_back(v);
    }
    cout << bfs(s, t);
    return 0;
}
