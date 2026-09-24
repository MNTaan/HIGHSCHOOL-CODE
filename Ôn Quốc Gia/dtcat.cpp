#include <bits/stdc++.h>
#define ll long long
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
const int maxN = 200000 + 10;
using namespace std;
pii m, n;
vector<pii> va, vb;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    while (cin >> m.x >> m.y >> n.x >> n.y)
    {
        va.push_back(m);
        vb.push_back(n);
    }
    ll dem = 0;
    for (int i = 0; i < va.size() - 1; i++)
        for (int j = i + 1; j < va.size(); j++)
        {
            pii a, b;
            a = va[i];
            b = vb[i];
            pii c, d;
            c = va[j];
            d = vb[j];
            ll a1 = b.y - a.y;
            ll b1 = b.x - a.x;
            ll a2 = d.y - c.y;
            ll b2 = d.x - c.x;
            ll dd = a1 * b2 - a2 * b1;
            if (dd != (ll)0)
                cout << i + 1 << "-" << j + 1 << endl, dem++;
        }
    if (dem == 0)
        cout << "NO";
    return 0;
}
