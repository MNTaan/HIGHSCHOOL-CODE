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
const int maxN = 2e3 + 10;
const int INF = 1e18;
const int MOD = 0;
using namespace std;
ll tinh(ll a, char toantu, ll b)
{
    if (toantu == '+')
        return a + b;
    if (toantu == '-')
        return a - b;
    if (toantu == '*')
        return a * b;
    return 0;
}
string itos(int x)
{
    stringstream result;
    result << x;
    return result.str();
}
string ngoac(string a, char opt, string b)
{
    return '(' + a + opt + b + ')';
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    file("bieuthuc");
    ll n;
    cin >> n;
    cin.ignore();

    vector<vector<long long>> giatri(n + 1);
    vector<vector<string>> bthuc(n + 1);

    for (int i = 1; i <= n; i++)
    {
        string s;
        getline(cin, s);
        long long th[4] = {0, 0, 0, 0};
        char tt[3];
        int so_tt = 0;
        for (char c : s)
        {
            if ('0' <= c && c <= '9')
            {
                th[so_tt] *= 10;
                th[so_tt] += c - '0';
            }
            else
            { 
                tt[so_tt] = c;
                so_tt++;
            }
        }

        if (so_tt == 1)
        {
            giatri[i].push_back(tinh(th[0], tt[0], th[1]));
            bthuc[i].push_back(s);
        }
        if (so_tt == 2)
        {
            giatri[i].push_back(tinh(tinh(th[0], tt[0], th[1]),
                                     tt[1], th[2]));
            bthuc[i].push_back(ngoac(itos(th[0]), tt[0], itos(th[1])) +
                               tt[1] + itos(th[2]));
            giatri[i].push_back(tinh(th[0], tt[0],
                                     tinh(th[1], tt[1], th[2])));
            bthuc[i].push_back(itos(th[0]) + tt[0] +
                               ngoac(itos(th[1]), tt[1], itos(th[2])));
        }
        if (so_tt == 3)
        {
            giatri[i].push_back(tinh(tinh(tinh(th[0], tt[0], th[1]),
                                          tt[1], th[2]),
                                     tt[2], th[3]));
            bthuc[i].push_back(ngoac(ngoac(itos(th[0]), tt[0], itos(th[1])),
                                     tt[1], itos(th[2])) +
                               tt[2] + itos(th[3]));
            giatri[i].push_back(tinh(tinh(th[0], tt[0], th[1]),
                                     tt[1], tinh(th[2], tt[2], th[3])));
            bthuc[i].push_back(ngoac(itos(th[0]), tt[0], itos(th[1])) + tt[1] + ngoac(itos(th[2]), tt[2], itos(th[3])));
            giatri[i].push_back(tinh(tinh(th[0], tt[0],
                                          tinh(th[1], tt[1], th[2])),
                                     tt[2], th[3]));
            bthuc[i].push_back(ngoac(itos(th[0]), tt[0],
                                     ngoac(itos(th[1]), tt[1], itos(th[2]))) +
                               tt[2] + itos(th[3]));

            giatri[i].push_back(tinh(th[0], tt[0],
                                     tinh(tinh(th[1], tt[1], th[2]), tt[2], th[3])));
            bthuc[i].push_back(itos(th[0]) + tt[0] +
                               ngoac(ngoac(itos(th[1]), tt[1], itos(th[2])), tt[2], itos(th[3])));
            giatri[i].push_back(tinh(th[0], tt[0],
                                     tinh(th[1], tt[1], tinh(th[2], tt[2], th[3]))));
            bthuc[i].push_back(itos(th[0]) + tt[0] +
                               ngoac(itos(th[1]), tt[1], ngoac(itos(th[2]), tt[2], itos(th[3]))));
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < giatri[i].size(); j++)
            cout << giatri[i][j] << " ";
        cout << endl;
        for (int j = 0; j < bthuc[i].size(); j++)
            cout << bthuc[i][j] << " ";
        cout << endl;
    }
    return 0;
}
