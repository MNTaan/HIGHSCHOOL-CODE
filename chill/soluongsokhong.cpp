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
const int maxN = 1e6 + 10;
using namespace std;
ll n;
ll so2[maxN], so5[maxN];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    ll T;
    so2[0] = so5[0] = 0;
    for (int i = 1; i <= 1e6; i++)
    {
        so2[i] = so2[i - 1];
        so5[i] = so5[i - 1];
        ll j = i;
        while (j % 2 == 0)
        {
            so2[i]++;
            j /= 2;
        }
        while (j % 5 == 0)
        {
            so5[i]++;
            j /= 5;
        }
    }
    cin >> T;
    while (T--)
    {
        cin >> n;
        cout << min(so2[n], so5[n]) << endl;
    }
    return 0;
}
