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
const int maxN = 1e6 + 10;
using namespace std;
ll n;
ll a[maxN], s[maxN], minl[maxN], minr[maxN];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    cin >> n;
    minl[0] = minr[n + 1] = 1e9;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    for (int i = 1; i <= n; i++)
        minl[i] = min(s[i], minl[i - 1]);
    for (int i = n; i >= 1; i--)
        minr[i] = min(s[i], minr[i + 1]);
    ll dem = 0;
  
    for (int i = 1; i <= n; i++)
    {
        if (s[n] - s[i - 1] + minl[i - 1] > 0 && minr[i] - s[i - 1] > 0)
            dem++;
    }
    cout << dem;
    return 0;
}
