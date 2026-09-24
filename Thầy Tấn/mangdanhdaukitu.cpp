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
const int maxN = 255 + 10;
using namespace std;
ll kt[maxN];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    file("mangdanhdaukitu");
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    fill(kt + 1, kt + 255 + 1, 0);
    for (auto i : s)
    {

        kt[i]++;
    }
    for (auto i : s)
    {
        if (kt[i] > 0)
        {
            cout << i << " " << kt[i];
            cout << endl;
            kt[i] = 0;
        }
    }
    return 0;
}
