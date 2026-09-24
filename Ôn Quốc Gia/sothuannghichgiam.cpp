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
bool dx(string s)
{
    string s1 = s;
    reverse(s1.begin(), s1.end());
    return s1 == s && s.size() != 1;
}
bool cmp(pair<string, int> a, pair<string, int> b)
{
    return (a.fi.size() != b.fi.size()) ? a.fi.size() > b.fi.size() : a.fi > b.fi;
}
map<string, int> m;
vector<pair<string, int>> v;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    string s;
    while (cin >> s)
    {
        if (dx(s))
            m[s]++;
    }
    for (auto c : m)
        v.push_back(c);
    sort(v.begin(), v.end(), cmp);
    for (auto c : v)
        cout << c.fi << " " << c.se << endl;
    return 0;
}
