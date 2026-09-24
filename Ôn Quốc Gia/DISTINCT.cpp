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
map<string, int> mp;
vector<string> v;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    ll n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string x;
        cin >> x;
        v.push_back(x);
    }
    for (auto c : v)
    {
        if (mp[c] == 0)
        {
            cout << c << endl;
            mp[c]++;
        }
    }
    return 0;
}
