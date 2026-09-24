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
const int maxN = 200000 + 10;
const int INF = 1e18;
const int MOD = 0;
using namespace std;
int a[maxN];
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    ll n;
    cin >> n;
    memset(a, 0, sizeof(a));
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        a[x]++;
        a[y + 1]--;
    }
    int p, q, r, s;
    int ckpq = 1;
    int ckrs = 1;
    for (int i = 1; i <= 8640000; i++)
    {
        a[i] = a[i - 1] + a[i];
    }
    cin >> p >> q >> r >> s;
    for (int i = p; i <= q; i++)
    {
        if (a[i] <= 0)
        {
            ckpq = 0;
            break;
        }
    }
    for (int i = r; i <= s; i++)
    {
        if (a[i] > 0)
        {
            ckrs = 0;
            break;
        }
    }
    int idx = 8640014, tmpbegin, tmpend, size = 0;
    for (int i = 1; i <= 8640000; i++)
    {
        if (a[i] > 0 && i < idx)
        {
            idx = i;
        }
        else if (a[i] <= 0)
        {
            if (i - idx > size)
            {
                tmpbegin = idx;
                tmpend = i - 1;
                size = i - idx;
            }
            idx = 8640014;
        }
    }
    int id = 8640014, tmpr, tmps, sz = 0;
    for (int i = 1; i <= 8640000; i++)
    {
        if (a[i] <= 0 && i < id)
        {
            id = i;
        }
        else if (a[i] > 0)
        {
            if (i - id > sz)
            {
                tmpr = id;
                tmps = i - 1;
                sz = i - id;
            }
            id = 8640014;
        }
    }
    cout << ckpq << endl
         << ckrs << endl;
    cout << tmpbegin << ' ' << tmpend << endl;
    cout << tmpr << ' ' << tmps;
    return 0;
}
