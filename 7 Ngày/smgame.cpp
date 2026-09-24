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
const int maxN = 1e5 + 10;
const int INF = 1e18;
const int MOD = 0;
using namespace std;
ll a[maxN], b[maxN];
ll n;
bool check_sub1()
{
    for (int i = 1; i <= n; i++)
    {
        if (a[i] > 2 || b[i] > 2)
            return false;
    }
    return true;
}
bool ck1(ll x)
{
    // cout<<"???";
    // cout << a[x - 1] << " " << b[x - 1] << " " << a[x + 1] << " " << b[x + 1] << endl;
    if (a[x - 1] == 1 && b[x - 1] == 1 && a[x + 1] == 1 && b[x + 1] == 1)
        return false;
    return true;
}
void sub1()
{
    ll dem[maxN];
    fill(dem + 1, dem + n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        dem[a[i]]++;
    }
    ll cka = 0;
    ll ckb = 0;
    if (dem[1] == n)
        cka = 1;
    if (dem[2] == n)
        cka = 2;
    fill(dem + 1, dem + n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        dem[b[i]]++;
    }
    if (dem[1] == n)
        ckb = 1;
    if (dem[2] == n)
        ckb = 2;
    if (cka != ckb && cka != 0 && ckb != 0)
    {
        cout << -1;
        return;
    }
    // cout << cka << " " << ckb << endl;
    ll demk = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] > b[i])
        {
            cout << -1;
            return;
        }
    }
    a[0] = a[n];
    a[n + 1] = a[1];
    b[0] = b[n];
    b[n + 1] = b[1];
    for (int i = 1; i <= n; i++)
    {
        if (a[i] != b[i] && !ck1(i))
        {
            // cout << i << endl;
            cout << -1;
            return;
        }
    }
    for (int i = 1; i <= n; i++)
        if (a[i] != b[i])
            demk++;
    cout << demk;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    file("smgame");
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    if (check_sub1())
        sub1();
    return 0;
}
