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
ll a[maxN];
ll n, m;
void tinh()
{
    priority_queue<ll, vector<ll>, greater<ll>> p;
    sort(a + 1, a + m + 1, greater<>());
    // for (int i = 1; i <= m; i++)
    //     cout << a[i];
    for (int i = 1; i <= n; i++)
        p.push(a[i]);
    for (int i = n + 1; i <= m; i++)
    {
        ll u = p.top();
        p.pop();
        p.push(u + a[i]);
    }
    while (p.size() != 1)
        p.pop();
    cout << p.top();
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    file("giacong");
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
        cin >> a[i];
    tinh();
    return 0;
}
