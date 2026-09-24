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
const int maxN = 1e6 + 10;
const int INF = 1e18;
const int MOD = 0;
using namespace std;
vector<ll> ord;
ll n = 0;
char val[maxN];
ll p[23][maxN], lev[maxN];
void TypeLetter(char L)
{
    val[++n] = L;
    lev[n] = lev[ord.back()] + 1;
    p[0][n] = ord.back();
    ord.pb(n);
    for (ll i = 1; i < 22; i++)
        p[i][n] = p[i - 1][p[i - 1][n]];
}
void UndoCommands(int U)
{
    ll f = (ll)(ord.size()) - U - 1;
    ord.pb(ord[f]);
}
ll jump(ll x, ll k)
{
    for (ll i = 21; i >= 0; i--)
    {
        if ((k >> i) & 1)
            x = p[i][x];
    }
    return x;
}
char GetLetter(int P)
{
    ll k = lev[ord.back()] - P - 1;
    ll f = jump(ord.back(), k);
    return val[f];
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    ord.pb(0);
    int st;
    cin >> st;
    int q;
    cin >> q;
    while (q--)
    {
        char x;
        cin >> x;
        if (x == 'T')
        {
            char c;
            cin >> c;
            TypeLetter(c);
        }
        else if (x == 'U')
        {
            int u;
            cin >> u;
            UndoCommands(u);
        }
        else if (x == 'P')
        {
            int i;
            cin >> i;
            i--;
            cout << GetLetter(i);
        }
    }
    return 0;
}
