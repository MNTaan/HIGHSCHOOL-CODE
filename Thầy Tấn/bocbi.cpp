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
bool dp[maxN];
ll n, a, b, c;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    file("bocbai");
    cin >> n >> a >> b >> c;
    memset(dp, false, sizeof(dp));
    int low = min(min(a, b), c);
    for (int i = low; i <= n; i++)
    {
        if ((i >= a && !dp[i - a]) || (i >= b && !dp[i - b]) || (i >= c && !dp[i - c]))
            dp[i] = true;
    }

    if (dp[n])
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
