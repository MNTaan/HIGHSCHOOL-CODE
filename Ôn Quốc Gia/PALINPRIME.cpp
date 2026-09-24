#include <bits/stdc++.h>
#define ll long long
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
const ll maxN = 1e6 + 10;
using namespace std;
ll l, r, cnt;
bool isprime(ll n)
{
    ll x = 0;
    ll a = 0;
    while (n > 0)
    {
        a = n % 10;
        x += a;
        n /= 10;
    }
    for (ll i = 2; i * i <= x; i++)
        if (x % i == 0)
            return false;
    return x > 1;
}
void check1(ll x)
{
    string s1 = to_string(x);
    string s2 = s1;
    reverse(s2.begin(), s2.end());
    ll newn = 0;
    s1 += s2;
    for (auto v : s1)
        newn = newn * 10 + (v - '0');
    if (newn >= l && newn <= r && isprime(newn))
        cnt++;
}
void check2(ll x)
{
    string s1 = to_string(x);
    string s2;
    for(ll i=0;i<s1.size()-1;i++)
        s2+=s1[i];
    reverse(s2.begin(),s2.end());
    ll newn = 0;
    s1+=s2;
    for (auto v : s1)
        newn = newn * 10 + (v - '0');
    if (newn >= l && newn <= r && isprime(newn))
        cnt++;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    cin >> l >> r;
    for (ll i = 1; i <= maxN; i++)
    {
        check1(i);
        check2(i);
    }
    cout<<cnt;
    return 0;
}
