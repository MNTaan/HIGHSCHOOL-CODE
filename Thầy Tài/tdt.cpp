#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define endl "\n"
#define x first
#define y second
#define pii pair<ll, ll>
#define file(name)                    \
    freopen(name ".inp", "r", stdin); \
    freopen(name ".out", "w", stdout);
#define fileTHHB                      \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout)
const int maxN = 1e5 + 10;
using namespace std;
ll dv, dr;
vector<pair<int, int>> va;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int u, v;
        cin >> u >> v;
        va.push_back({u, 1});
        va.push_back({v, -1});
    }
    sort(va.begin(), va.end());
    ll dem = va[0].y;
    ll bd, kt, luu = 0;
    bd = va[0].x;
    for (int i = 1; i < va.size(); i++)
    {
        dem += va[i].y;
        if (dem == 0)
        {
            luu = max(luu, va[i].x - bd);
            bd = va[i + 1].x;
        }
    }
    cout << luu;
    return 0;
}
