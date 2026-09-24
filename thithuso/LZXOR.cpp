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
const int maxN = 100005 + 10;
const int INF = 1e18;
const int MOD = 0;
using namespace std;
int L[maxN << 2], R[maxN << 2];
int s[maxN << 2][22], tag[maxN << 2][22];
int n, q, a[maxN];
void up(int i)
{
    int lc = (i << 1), rc = (lc | 1);
    for (int x = 0; x <= 20; x++)
    {
        s[i][x] = s[lc][x] + s[rc][x];
    }
}

void down(int i)
{
    int lc = (i << 1), rc = (lc | 1);
    for (int x = 0; x <= 20; x++)
    {
        if (tag[i][x])
        {
            s[lc][x] = R[lc] - L[lc] + 1 - s[lc][x];
            s[rc][x] = R[rc] - L[rc] + 1 - s[rc][x];
            tag[lc][x] ^= 1;
            tag[rc][x] ^= 1;
            tag[i][x] = 0;
        }
    }
}

void build(int l, int r, int i)
{
    int mid = (l + r) >> 1;
    L[i] = l;
    R[i] = r;
    if (l == r)
    {
        for (int x = 0; x <= 20; x++)
        {
            s[i][x] = ((a[l] & (1 << x)) > 0);
        }
        return;
    }
    build(l, mid, (i << 1));
    build(mid + 1, r, ((i << 1) | 1));
    up(i);
}

void process(int l, int r, int i, int type, long long &value)
{
    if (l > R[i] || r < L[i])
    {
        return;
    }
    if (l <= L[i] && r >= R[i])
    {
        if (type == 1)
        {
            for (int x = 0; x <= 20; x++)
            {
                value += (1LL << x) * s[i][x];
            }
        }
        else
        {
            for (int x = 0; x <= 20; x++)
            {
                if (value & (1 << x))
                {
                    s[i][x] = R[i] - L[i] + 1 - s[i][x];
                    tag[i][x] ^= 1;
                }
            }
        }
        return;
    }
    down(i);
    process(l, r, (i << 1), type, value);
    process(l, r, ((i << 1) | 1), type, value);
    up(i);
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    file("LZXOR");
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    build(1, n, 1);
    cin >> q;
    while (q--)
    {
        int type, l, r, x;
        cin >> type;
        if (type == 0)
        {
            cin >> l >> r >> x;
            int value = x;
            process(l, r, 1, 2, value);
        }
        else
        {
            cin >> l >> r;
            int ans = 0;
            process(l, r, 1, 1, ans);
            cout << ans << '\n';
        }
    }
    return 0;
}
