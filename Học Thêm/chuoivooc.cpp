#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
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
const int maxN = 200000 + 10;
using namespace std;
ll a[maxN], f1[maxN], f2[maxN];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    ll n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        f1[i] = 1;
        f2[i] = 1;
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (a[j] <= a[i])
                f1[i] = max(f1[i], f1[j] + 1);
        }
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (a[j] >= a[i])
                f2[i] = max(f2[i], f2[j] + 1);
        }
    }
    ll Max = 0;
    for (int i = 1; i <= n; i++)
        Max = max(Max, f1[i] + f2[i] - 1);
    // cout<<f2[3];
    cout << Max;
    return 0;
}
