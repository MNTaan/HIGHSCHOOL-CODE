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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    string s, ss;
    cin >> s >> ss;
    if (s == "" || ss == "")
        cout << 0;
    else
    {
        double h1 = 0, p1 = 0, h2 = 0, p2 = 0;
        h1 = double(s[0] - '0') * 10;
        h1 += double(s[1] - '0');
        h2 = double(ss[0] - '0') * 10;
        h2 += double(ss[1] - '0');
        p1 = double(s[3] - '0') * 10;
        p1 += double(s[4] - '0');
        p2 = double(ss[3] - '0') * 10;
        p2 += double(ss[4] - '0');
        // cout<<h1<<" "<<p1<<endl;
        // cout<<h2<<" "<<p2<<endl;
        if (h1 < 7)
            h1 = 7, p1 = 0;
        if (h2 > 15)
            h2 = 15, p2 = 0;
        double tong1 = h1 + (p1 / 60);
        double tong2 = h2 + (p2 / 60);
        cout << fixed << setprecision(1) << tong2 - tong1;
    }
    return 0;
}
