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
string ItoS(int x)
{
    string temp = "";
    while (x != 0)
    {
        temp += x % 10 + '0';
        x /= 10;
    }
    reverse(temp.begin(), temp.end());
    return temp;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    ll n, m;
    cin >> n >> m;
    string s;
    for (int i = 1; i <= n; i++)
        s += ItoS(i);
    ll vtc = 0;
    for (int i = 1; i < s.size(); i++)
    {
        if (s[vtc] == '9')
        {   
            vtc=i; 
            continue;
        }
        if (m > 0)
        {
            if (s[i] > s[vtc])
            {
                s[vtc] = '*';
                vtc = i;
                m--;
            }
            else
            {
                s[i] = '*';
                m--;
            }
        }
    }
    for (int i = 1; i < s.size(); i++)
        if (s[i] != '*')
            cout << s[i];
    return 0;
}
