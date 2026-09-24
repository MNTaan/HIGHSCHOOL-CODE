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
const int maxN = 1009, z = 1000;
using namespace std;
int n, e;
ll dp[2][1001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    cin >> e >> n;
    int f = 0, s = 1;
    for (int i = 1; i < 1e8; i++)
    {
        for (int j = 1; j <= e; j++)
        {
            dp[f][j] = dp[s][j - 1] + 1 + dp[s][j];
            if (dp[f][j] >= n)
            {
                cout << i;
                return 0;
            }
        }
        swap(f, s);
    }
    return 0;
}