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
ll n, a[maxN];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    ll a, b;
    cin >> a >> b;
    if (a > b)
        cout << "TRUE";
    else
    {
        if ((a % 2 == 0 && b % 2 == 0) || (a % 2 != 0 && b % 2 != 0) && a < b)
            cout << "FALSE";
        else
            cout << "TRUE";
    }
    return 0;
}
