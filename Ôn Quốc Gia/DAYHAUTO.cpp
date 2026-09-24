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
int n;
vector<string> a;
map<string, bool> mp;
bool cmp(string a, string b)
{
    if (a.size() == b.size())
        return a > b;
    return a.size() > b.size();
}
int calc(string s)
{
    int cnt = s.size();
    for (int i = 0; i < s.size() - 1; i++)
    {
        string x = "";
        for (int j = i + 1; j < s.size(); j++)
            x += s[j];
        if (mp[x])
            cnt += x.size();
    }
    return cnt;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    cin >> n;
    cin.ignore();
    for (int i = 1; i <= n; i++)
    {
        string x;
        cin >> x;
        a.pb(x);
        mp[x] = 1;
    }
    int ans = 0;
    sort(a.begin(), a.end(), cmp);
    for (int i = 0; i < a.size(); i++)
    {
        ans = max(ans, calc(a[i]));
    }
    cout << ans;
    return 0;
}
