#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

#define all(v) v.begin(), v.end()
#define fi first
#define se second
#define int long long

int n, zero = 0;
vector<int> a;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

#define File(TASK)                         \
    if (fopen(TASK ".inp", "r"))           \
    {                                      \
        freopen(TASK ".inp", "r", stdin);  \
        freopen(TASK ".out", "w", stdout); \
    }
    File("LSEQ");

    cin >> n;
    a.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] != 0)
            a[i] += 1e7 + 1;
    }

    sort(all(a));

    for (int i = 0; i < n; i++)
    {
        if (a[i] != 0)
            break;
        zero++;
    }

    a.erase(unique(all(a)), a.end());
    if (zero)
        a.erase(a.begin());

    n = a.size();

    vector<pair<int, int>> segments;
    int l = a[0], r = a[0];

    for (int i = 1; i <= n; i++)
    {
        if (i == n || a[i] - a[i - 1] != 1)
        {
            segments.push_back({l, a[i - 1]});
            if (i < n)
                l = a[i];
        }
    }

    n = segments.size();
    int maxlen = 0, mincost = 0, curcost = 0;
    l = 0, r = 0;

    while (l <= r && r < n)
    {
        if (r + 1 < n && curcost + (segments[r + 1].fi - segments[r].se - 1) <= zero)
        {
            curcost += (segments[r + 1].fi - segments[r].se - 1);
            r++;
        }
        else
        {
            int length = segments[r].se - segments[l].fi + 1;
            if (length > maxlen)
            {
                maxlen = length;
                mincost = curcost;
            }
            else if (length == maxlen)
            {
                mincost = min(mincost, curcost);
            }

            if (l < r)
            {
                curcost -= (segments[l + 1].fi - segments[l].se - 1);
                l++;
            }
            else
            {
                l++;
                r++;
            }
        }
    }

    cout << maxlen + (zero - mincost) << "\n";
    return 0;
}