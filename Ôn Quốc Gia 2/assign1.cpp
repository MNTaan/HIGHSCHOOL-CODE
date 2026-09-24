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
const int maxN = 200 + 10;
const int INF = 1e18;
const int MOD = 0;
using namespace std;
ll n, c[maxN][maxN], a[maxN], b[maxN], d[maxN], q[maxN], mid, t;
int find()
{
    int i, nq = 0, x, y;
    for (int i = 1; i <= n; i++)
        d[i] = 0;
    for (int i = 1; i <= n; i++)
        if (!a[i])
        {
            nq++;
            q[nq] = i;
        }
    i = 1;
    while (i <= nq)
    {
        x = q[i++];
        for (int y = 1; y <= n; y++)
            if (c[x][y] <= mid && !d[y])
            {
                d[y] = x;
                if (!b[y])
                {
                    t = y;
                    return 1;
                }
                nq++;
                q[nq] = b[y];
            }
    }
    return 0;
}

void inc()
{
    int x, y;
    while (t)
    {
        x = d[t];
        y = t;
        t = a[x];
        a[x] = y;
        b[y] = x;
    }
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    file("THHB");
    ll i, j, low = 1000000, high = 0, re, s;
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> c[i][j];
            low = min(low, c[i][j]);
            high = max(high, c[i][j]);
        }
    while (low <= high)
    {
        mid = (low + high) / 2;
        for (int i = 1; i <= n; i++)
        {
            a[i] = 0;
            b[i] = 0;
        }
        while (find())
            inc();
        s = 0;
        for (int i = 1; i <= n; i++)
            if (a[i])
                s++;
        if (s == n)
        {
            high = mid - 1;
            re = mid;
        }
        else
            low = mid + 1;
    }
    cout << re << endl;
    return 0;
}
