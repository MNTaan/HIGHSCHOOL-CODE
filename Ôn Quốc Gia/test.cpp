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
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ll t, a, b, dem;
    cin >> a;
    while (a--)
    {
        cin >> b;
        for (int i = 1; i <= b; i++)
        {
            for (int j = i; j <= b; j++)
                if (__gcd(i, j) == 1)
                    cout << "(" << i << "," << j << ")" << endl;
        }
    }

    return 0;
}
