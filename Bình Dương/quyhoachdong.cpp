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
    int a, b, c, m;
    while (cin >> a >> b >> c >> m)
    {

        if (a == 0 || b == 0 || c == 0 || m < 3)
        {
            cout << "YES" << endl;
            continue;
        }
        int res = (a + b + c);
        if (res < m )
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
