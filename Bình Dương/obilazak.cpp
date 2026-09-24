#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define endl "\n"
#define fi first
#define se second
#define pii pair<ll, ll>
#define file(name)                         \
    if (fopen(name ".inp", "r"))           \
    {                                      \
        freopen(name ".inp", "r", stdin);  \
        freopen(name ".out", "w", stdout); \
    }
#define fileTHHB                            \
    if (fopen("input.txt", "r"))            \
    {                                       \
        freopen("input.txt", "r", stdin);   \
        freopen("output.txt", "w", stdout); \
    }
const int maxN = 2e5 + 10;
using namespace std;
int k, a[maxN], vis[maxN];
vector<int> group[maxN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;

    cin >> k;
    for (int i = 1; i <= (1 << k) - 1; i++)
        cin >> a[i];
    for (int i = 1; i <= (1 << k) - 1; i++)
    {
        int p = i;
        for (int j = 1; j <= k; j++)
        {
            if (vis[p])
                continue;
            vis[p] = 1;
            group[k - j].pb(a[p]);
            p += (1 << (j - 1));
            if (p > (1 << k) - 1)
                break;
        }
    }

    for (int i = 0; i < k; i++)
    {
        for (auto j : group[i])
            cout << j << " ";
        cout << "\n";
    }

    return 0;
}
