#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m, f[100000];
string s, sd;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("nhiphan1.inp", "r", stdin);
    // freopen("nhiphan1.out", "w", stdout);
    cin >> n;
    cin >> s;
    cin.ignore();
    cin >> m;
    f[0] = 1;
    for (int i = 1; i <= n; i++)
        f[i] = f[i - 1] * 2;
    long long vts = 0;
    string vtm = "";
    s = " " + s;
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] == '1')
        {
            vts += f[n - i];
            // cout<<f[n-i]<<endl;
        }
    }
    cout << vts + 1 << endl;
    string c = "";
    for (int i = 1; i <= n; i++)
        c = c + '0';
    for (int i = 0; i < n; i++)
    {
        if (m > f[n - i - 1])
        {
            c[i] = '1';
            m = m - f[n - i - 1];
        }
    }
    cout << c;
    return 0;
}
