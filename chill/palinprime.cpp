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
ll L, R;
ll d = 0;
bool isPrime(ll x)
{
    ll xet = 0;
    while (x != 0)
        xet += x % 10, x /= 10;
    if (xet <= 1)
        return false;
    for (int i = 2; i * i <= xet; i++)
        if (xet % i == 0)
            return false;
    return true;
}

void Work(ll x)
{

    ll tmp = x;
    ll daongc = 0;
    ll buffer = 1;

    while (tmp != 0)
    {
        daongc = daongc * 10 + tmp % 10;
        buffer *= 10;
        tmp /= 10;
    }
    // cout << x << endl;

    ll x1 = x * buffer + daongc;
    ll x2 = x / 10 * buffer + daongc;
    // cout << x1 << " " << x2 << endl;
    if (L <= x1 && x1 <= R && isPrime(x1))
        d++;
    if (L <= x2 && x2 <= R && isPrime(x2))
        d++;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    cin >> L >> R;
    for (int i = 1; i <= 1000000; i++)
        Work(i);
    cout<<d;
    return 0;
}
