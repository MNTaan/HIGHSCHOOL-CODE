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
const int maxN = 3e3 + 69;
using namespace std;
ll n, t;
pii edge[maxN];
struct pt
{
    bitset<3010> hs;
    ll val;
};
pt hpt[maxN];
ll b[maxN], c[maxN];
void solve()
{
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        hpt[i].hs.reset();
        c[i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        int x = edge[i].first;
        int y = edge[i].second;
        hpt[x].hs[y] = 1;
        hpt[y].hs[x] = 1;
        hpt[i].hs[i] = 1;
        hpt[i].val = 1 ^ b[i];
    }

    for (int i = 1; i <= n; i++)
    {
        int found = -1;
        for (int j = 1; j <= n; j++)
            if (hpt[i].hs[j] == 1)
            {
                found = j;
                break;
            }
        if (found == -1 && hpt[i].val == 1)
        {
            cout << -1 << endl;
            return;
        }
        if (found == -1)
            continue;
        for (int f = 1; f <= n; f++)
        {
            if (hpt[f].hs[found] == 0 || f == i)
                continue;
            hpt[f].hs ^= hpt[i].hs;
            hpt[f].val ^= hpt[i].val;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (hpt[i].hs[j] == 1)
            {
                c[j] = hpt[i].val;
                break;
            }
        }
    }
    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        if (c[i])
            ans.push_back(i);
    }
    cout << ans.size() << " ";
    for (auto it : ans)
        cout << it << " ";
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    cin >> n >> t;
    for (int i = 1; i <= n; i++)
        cin >> edge[i].first >> edge[i].second;
    for (int i = 1; i <= t; i++)
        solve();
    return 0;
}
