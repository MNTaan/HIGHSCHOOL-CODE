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
ll ans[maxN];
ll n;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;

    cin >> n;
    cin >> s;
    ll len = s.size();
    s = ' ' + s;
    for (int j = len / 2; j >= 1; j--)
    {
        int dem = 0;
        for (int i = 1; i <= j; i++)
            dem += (s[i] != s[i + j]);
        ans[j] = dem;
        for (int i = j + 1; i <= len - j; i++)
        {
            dem += (s[i] != s[i + j]) - (s[i - j] != s[i]);
            if (ans[j] > dem)
            {
                ans[j] = dem;
            }
        }
    }
    len = len / 2;
    while (n--)
    {
        int k;
        cin >> k;
        for (int i = len; i >= 0; i--)
        {
            if (ans[i] <= k)
            {
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}
