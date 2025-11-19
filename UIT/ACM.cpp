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
const int maxN = 1000 + 10;
using namespace std;
ll n, m;
char s[maxN][maxN];
ll dx[4] = {1, 0, 0, -1};
ll dy[4] = {0, 1, -1, 0};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> s[i][j];
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int cm = 0, ca = 0;
            if (s[i][j] != 'C')
                continue;
            for (int k = 0; k < 4; k++)
            {
                cm += (s[i + dx[k]][j + dy[k]] == 'M');
                ca += (s[i + dx[k]][j + dy[k]] == 'A');
            }
            ans += cm * ca;
        }
    }
    cout << ans;
    return 0;
}
