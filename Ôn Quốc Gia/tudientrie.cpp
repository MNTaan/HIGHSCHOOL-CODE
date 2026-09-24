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
const int maxN = 100000 + 10;
using namespace std;
map<string, int> mp;
int node[maxN];
int child[maxN][26];
int cnt;
void build(string s)
{
    int u = 0;
    for (auto c : s)
    {
        int k = c - 'a';
        if (!child[u][k])
            child[u][k] = ++cnt;
        u = child[u][k];
    }
    node[u] = true;
}
bool ck(string &s)
{
    int u = 0;
    for (auto c : s)
    {
        int k = c - 'a';
        if (!child[u][k])
            return 0;
        u = child[u][k];
    }
    return node[u];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    file("tudien");
    ll n, q;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        build(s);
    }
    cin >> q;
    int dem = 0;
    for (int i = 1; i <= q; i++)
    {
        string s;
        cin >> s;
        if (ck(s))
            dem++;
    }
    cout << dem;
    return 0;
}