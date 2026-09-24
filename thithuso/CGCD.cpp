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
const int maxN = 1e7 + 10;
const int INF = 1e18;
const int MOD = 0;
using namespace std;
ll a, b;
vector<int> sang(int maxN)
{
    vector<int> mob(maxN + 5, 1);
    vector<bool> nt(maxN + 5, 1);
    for (int i = 2; i <= maxN; i++)
    {
        if (nt[i])
        {
            for (int j = i; j <= maxN; j += i)
            {
                nt[j] = false;
                mob[j] *= -1;
            }
            for (int j = 1LL * i * i; j <= maxN; j += 1LL * i * i)
            {
                mob[j] = 0;
            }
        }
    }
    return mob;
}

int kq(int n, int m)
{
    int maxN = min(n, m);
    vector<int> mob = sang(maxN);
    int ans = 0;
    for (int k = 1; k <= maxN; k++)
    {
        ans += 1LL * mob[k] * (n / k) * (m / k);
    }
    return ans;
}
void sub2()
{
    cout << kq(a, b);
}

void sub1()
{
    int cnt = 0;
    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            if (__gcd(i, j) == 1)
                cnt++;
        }
    }
    cout << cnt;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    file("cgcd");
    cin >> a >> b;
    if (a <= 1000 && b <= 1000)
        sub1();
    else
        sub2();
    return 0;
}
