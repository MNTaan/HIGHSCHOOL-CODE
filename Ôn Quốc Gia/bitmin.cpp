#include <bits/stdc++.h>
#define ll long long
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
ll a[maxN], bit[maxN], n;
void build(int i, ll v)
{
    int idx = i;
    while (idx <= n)
    {
        bit[idx] = min(bit[idx], v);
        idx += (idx & (-idx));
    }
}
ll getmin(int u, int v)
{
    ll ans = 1e18;
    int x;
    while (u <= v)
    {
        x = v - (v & (-v)) + 1;
        if (u <= x)
        {
            ans = min(ans, bit[v]);
            v -= (v & (-v));
        }
        else
        {
            ans = min(ans, a[v]);
            v -= 1;
        }
    }
    return ans;
}
void upd(int i, ll v)
{
    if (i > n)
        return;
    bit[i] = min(a[i],v);
    int L = i - (i & -i) + 1;
    int R = i - 1;
    while (L <= R)
    {
        bit[i] = min(bit[i], bit[R]);
        R -= (R & -R);
    }
    int cha = i + (i & -i);
    upd(cha,v);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    cin >> n;
    memset(bit, 0x3f, sizeof bit);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        build(i, a[i]);
    }
    ll p;
    cin >> p;
    while (p--)
    {
        ll x, u, v;
        cin >> x >> u >> v;
        if (x == 0)
            a[u]=v,upd(u, v);
        else
            cout << getmin(u, v) << endl;
    }
    return 0;
}
