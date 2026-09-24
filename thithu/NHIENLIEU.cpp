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
const int N = 2e5 + 69;
int n, l, p;
pair<int, int> a[N];
void Solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].fi >> a[i].se;
    cin >> l >> p;
    for (int i = 1; i <= n; i++)
        a[i].fi = l - a[i].fi;
    sort(a + 1, a + n + 1);
    int cnt = 0;
    a[n + 1].fi = l;
    priority_queue<int, vector<int>> q;
    for (int i = 1; i <= n; i++)
    {
        if (a[i].fi - a[i - 1].fi <= p)
        {
            p -= a[i].fi - a[i - 1].fi;
            q.push(a[i].second);
        }
        else
        {
            while (p < a[i + 1].fi - a[i].fi)
            {
                if (q.empty())
                {
                    cout << -1 << endl;
                    return;
                }
                else
                {
                    p += q.top();
                    q.pop();
                    cnt++;
                }
            }
            p -= a[i].first - a[i - 1].first;
            q.push(a[i].se);
        }
    }
    cout << cnt << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    file("nhienlieu");
    ll T;
    cin >> T;
    while (T--)
    {
        Solve();
    }
    return 0;
}
