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
const int maxN = 1e6 + 10;
using namespace std;
string a, b;
ll demt = 0, demh = 0, dems = 0;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    ll T;
    bool check = true;
    cin >> T;
    while (T--)
    {
        check = true;
        getline(cin, a);
        getline(cin, b);
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] == '?' || b[i] == '?')
                continue;
            if (a[i] != b[i])
            {
                cout << 0 << endl;
                check = false;
                break;
            }
        }
        if (!check)
            continue;
        cout << 1 << endl;
    }
    return 0;
}
