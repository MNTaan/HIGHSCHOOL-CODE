#include <bits/stdc++.h>
#define ll long long
#define int long long
#define ld long double
#define pb push_back
#define endl "\n"
#define fi first
#define se second
#define pii pair<ll, ll>

#define fileTHHB                            \
    if (fopen("input.txt", "r"))            \
    {                                       \
        freopen("input.txt", "r", stdin);   \
        freopen("output.txt", "w", stdout); \
    }
const int maxN = 2e5 + 5;
const int INF = 1e18;
const int MOD = 0;
ll mod[] = {(int)1e9 + 7, (int)1e9 + 9};
const ll base = 31;
using namespace std;
ll n, k, res, tmpL, tmpI;
ll sz[maxN];
ll P[2][maxN];
vector<ll> h[2][maxN];
string s[maxN];
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> s[i];
    for (int j = 0; j < 2; j++)
    {
        P[j][0] = 1;
        for (int i = 1; i < maxN; i++)
            P[j][i] = P[j][i - 1] * base % mod[j];
    }
    for (int i = 1; i <= n; i++)
        s[i] = ' ' + s[i];

    int ansI, ansL, ansR;
    for (int k = 0; k < 2; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            h[k][i].resize(s[i].size());
            for (int j = 1; j < s[i].size(); j++)
                h[k][i][j] = (h[k][i][j - 1] * base + s[i][j] - 'A') % mod[k];
        }
    }

    for (int l = 1, r = 2e5; l <= r;)
    {
        int m = (l + r) >> 1;

        map<pair<ll, ll>, pair<int, int>> dp;
        res = tmpL = tmpI = 0;

        for (int i = 1; i <= n; i++)
        {
            if (m > s[i].size())
                continue;
            for (int j = 1; j + m <= s[i].size(); j++)
            {
                int getHash0 = (h[0][i][j + m - 1] - h[0][i][j - 1] * P[0][m] + mod[0] * mod[0]) % mod[0];
                int getHash1 = (h[1][i][j + m - 1] - h[1][i][j - 1] * P[1][m] + mod[1] * mod[1]) % mod[1];
                pair<int, int> pairH = make_pair(getHash0, getHash1);
                if (dp.count(pairH) == 0)
                    dp[pairH] = {i, 1};
                auto &it = dp[pairH];
                if (it.first != i)
                {
                    it.second++;
                    it.first = i;
                }
                if (res < it.second)
                {
                    res = it.second;
                    tmpI = i;
                    tmpL = j;
                    if (res >= k)
                        break;
                }
                if (res >= k)
                    break;
            }
        }
        if (res >= k)
        {
            ansI = tmpI;
            ansL = tmpL;
            ansR = tmpL + m;
            l = m + 1;
        }
        else
            r = m - 1;
    }
    for (int i = ansL; i < ansR; i++)
        cout << s[ansI][i];
    return 0;
}
