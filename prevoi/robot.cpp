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
ll a[maxN], b[maxN], p[maxN];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    file("ROBOT");
    ll n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i] >> b[i] >> p[i];
    cout << -1;
    return 0;
}
