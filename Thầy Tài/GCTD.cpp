#include <bits/stdc++.h>
#define ll long long
#define int long long
#define ld long double
#define pb push_back
#define endl "\n"
#define x first
#define y second
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
pii p[maxN];
ll dem[maxN];
pii tru(pii A, pii B)
{
    return pii(A.x - B.x, A.y - B.y);
}
double operator*(pii A, pii B)
{
    return (A.x * B.y - A.y * B.x);
}
bool check(pii A, pii B, pii C)
{
    double t = tru(B, A) * tru(C, B);
    return t != 0;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    ll n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> p[i].x >> p[i].y;
    ll cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            for (int k = j + 1; k <= n; k++)
            {
                if (check(p[i], p[j], p[k]))
                {
                    cnt++;
                    dem[i] += 1;
                    dem[j] += 1;
                    dem[k] += 1;
                }
            }
        }
    }
    ll Min = 1e18;
    for (int i = 1; i <= n; i++)
    {
        Min = min(Min, dem[i]);
        // cout<<i<<" "<<dem[i]<<endl;
    }
    // cout<<Min;
    cout << cnt << endl;
    for (int i = 1; i <= n; i++)
        if (dem[i] == Min)
        {
            cout << i;
            break;
        }
    return 0;
}
