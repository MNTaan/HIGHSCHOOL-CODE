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
string s;
map<char, ll> mp;
void sub1()
{
    ll dem = 0;
    for (int i = 0; i < s.size() - 1; i++)
    {
        for (int j = i + 1; j < s.size(); j++)
        {
            if (mp[s[i]] == 1 && mp[s[j]] == 0)
                dem++;
            if (mp[s[i]] == 0 && mp[s[j]] == 1)
                dem++;
        }
    }
    cout << dem;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    file("tuvung");
    cin >> s;
    mp['a'] = 1;
    mp['e'] = 1;
    mp['i'] = 1;
    mp['o'] = 1;
    mp['u'] = 1;
    ll na = 0, pa = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (mp[s[i]] == 1)
            na++;
        else
            pa++;
    }
    cout << na * pa;
    return 0;
}
