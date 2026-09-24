#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define x first
#define y second
#define pii pair<ll, ll>
#define file(name)                    \
    freopen(name ".inp", "r", stdin); \
    freopen(name ".out", "w", stdout);
#define fileTHHB                      \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout)
const int maxN = 100000 + 10;
using namespace std;
pii a[maxN];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].x >> a[i].y;
    a[n + 1].x = a[1].x;
    a[n + 1].y = a[1].y;
    int s1 = 0, s2 = 0;
    for (int i = 1; i <= n; i++)
    {
        s1 += a[i].x * a[i + 1].y;
        s2 += a[i + 1].x * a[i].y;
    }
    if(s1-s2<0)
        cout<<"CW"<<" ";
    else
        cout<<"CCW"<<" ";
    double s = (double)abs(s1 - s2) / 2;
    cout << fixed << setprecision(1) << s;
    return 0;
}