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
ll n, m, k, dem;
string nhiphan(long long k)
{
    string s = "";
    while (k != 0)
    {
        if (k % 2 == 0)
            s = s + '0';
        else
            s = s + '1';
        k = k / 2;
    }
    return s;
}
long long chuyen(string s)
{
    m = 0;
    for (int i = s.size() - 1; i >= 0; i--)
        m = m * 10 + int(s[i] - 48);
    return m;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    file("boiso");
    cin >> n;
    long long i = 1;
    while (true)
    {
        m = chuyen(nhiphan(i));
        if (m % n == 0)
        {
            cout << m;
            return 0;
        }
        i++;
    }
    return 0;
}
