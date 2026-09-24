#include <bits/stdc++.h>
#define ll long long
#define int long long
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
const int maxN = 200000 + 10;
const int INF = 1e18;
const int MOD = 0;
using namespace std;
int n;
vector<string> ve;
string tach(string s, int id)
{
    ve.clear();
    stringstream ss(s);
    string word;
    while (ss >> word)
    {
        ve.pb(word);
    }
    int x = stoi(ve.back());
    return ve[x - 1];
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    cin >> n;
    cin.ignore();
    for (int i = 1; i <= n; i++)
    {
        string t;
        getline(cin, t);
        int j = 1;
        cout << tach(t, i) << " ";
    }
    return 0;
}
