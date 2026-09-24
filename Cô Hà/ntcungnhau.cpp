#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool check[100000000];
void snt(ll n)
{
    memset(check, true, sizeof(check));
    check[0] = false;
    check[1] = false;
    for (int i = 2; i * i <= n; i++)
    {
        if (check[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                check[j] = false;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("ntcungnhau.inp", "r", stdin);
    freopen("ntcungnhau.out", "w", stdout);
    ll t, a, b, dem;
    cin >> t;
    snt(1e6);
    while (t--)
    {
        cin >> a;
        dem = 1;
        for (int i = 1; i <= a; i++)
            if (check[i] == true)
                dem++;
        cout << dem << endl;
    }
    return 0;
}
