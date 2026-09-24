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
const int maxN = 1e6;
using namespace std;
ll n;
ll a[maxN + 10];
ll f[2 * maxN + 10];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    file("mangdanhdau");
    cin >> n;
    fill(f + 1, f + n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        f[a[i] + maxN]++;
        // cout << a[i] + maxN << endl;
    }

    for (int i = 1; i <= maxN; i++)
    {
        if (f[i] > 0)
        {
            cout << i - maxN << " " << f[i];
            f[i] = 0;
            cout << endl;
            // cout<<i<<endl;
        }
    }
    for (int i = maxN + 1; i <= 2 * maxN; i++)
    {
        if (f[i] > 0)
        {
            cout << i - maxN << " " << f[i];
            f[i] = 0;
            cout << endl;
        }
    }
    return 0;
}
