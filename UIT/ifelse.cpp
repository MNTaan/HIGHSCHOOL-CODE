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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    ll t, n, k, x;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cin >> n >> k >> x;
        if (x != 1)
        {
            cout << "YES\n";
            cout << n << endl;
            for (int i = 1; i <= n; i++)
                cout << 1 << " ";
            cout << endl;
            continue;
        }
        else if (x == 1)
        {
            if (k == 1)
                cout << "NO" << endl;
            else if (k == 2)
            {
                ll res = 0;
                if (n % 2 != 0)
                    cout << "NO" << endl;
                else
                {
                    for (int i = 1; i <= n / 2; i++)
                        res++;
                    cout << "YES" << endl;
                    cout << res << endl;
                    for (int i = 1; i <= n / 2; i++)
                        cout << 2 << " ";
                    cout << endl;
                }
            }
            else
            {
                ll res = 0;
                if (n % 2 != 0)
                {
                    cout << "YES" << endl;
                    res++;
                    for (int i = 1; i <= (n - 3) / 2; i++)
                        res++;
                    cout << res << endl;
                    cout << 3 << " ";
                    for (int i = 1; i <= (n - 3) / 2; i++)
                        cout << 2 << " ";
                    cout << endl;
                }
                else
                {
                    cout << "YES" << endl;
                    for (int i = 1; i <= n / 2; i++)
                        res++;
                    cout << res << endl;
                    for (int i = 1; i <= n / 2; i++)
                        cout << 2 << " ";
                    cout << endl;
                }
            }
        }
    }
    return 0;
}
