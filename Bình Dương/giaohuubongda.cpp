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
ll n, T, k;
pii p[maxN];
ll a[10001][1001];
void tlt(ll l, ll r)
{
    for (int i = l; i <= r; i++)
    {
        for (int j = l; j <= r; j++)
        {
            for (int k = l; k <= r; k++)
            {
                if (a[i][j] == 1 && a[j][k] == 1 && a[k][i] == 1)
                {
                    cout << 3 << " " << i << " " << j << " " << k;
                    return;
                }
            }
        }
    }
    cout << -1;
}
vector<ll> v[2];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    cin >> n >> T >> k;
    for (int i = 1; i <= T; i++)
        cin >> p[i].fi >> p[i].se;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    if (k == 1)
    {
        for (int t = 1; t <= T; t++)
        {
            ll f = 0, s = 1;
            v[f].clear();
            v[s].clear();
            v[f].push_back(p[t].fi);
            for (int i = p[t].fi + 1; i <= p[t].se; i++)
            {
                v[s].clear();
                int mid = 0;
                for (int x : v[f])
                {
                    if (mid)
                    {
                        v[s].push_back(x);
                        continue;
                    }
                    if (a[x][i] == 0)
                    {
                        v[s].push_back(i);
                        v[s].push_back(x);
                        mid = 1;
                    }
                    else
                        v[s].push_back(x);
                }
                if (mid == 0)
                    v[s].push_back(i);
                swap(f, s);
            }
            cout << p[t].se - p[t].fi + 1 << ' ';
            for (int i : v[f])
                cout << i << ' ';
        }
    }
    else
    {
        for (int i = 1; i <= T; i++)
        {
            tlt(p[i].fi, p[i].se);
            cout << endl;
        }
    }

    return 0;
}
