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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    ll u, v, x1, x2, y1, y2, d;
    string vt[9] = {"sw", "s", "se", "w", "0", "e", "nw", "n", "ne"};
    ll a, b, z;
    if (u > x2)
        a = 0;
    else if (u >= x1)
        a = 1;
    else
        a = 2;
    if (v > y2)
        b = 0;
    else if (v >= y1)
        b = 1;
    else
        b = 2;
    z = 3 * b + a;
    return 0;
}
