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
const int maxN = 300000 + 10;
using namespace std;
ll n,m,a[maxN];
bool check(int mid) {
    int cnt = 0;
    for (int i = 1;i <= n;i++) {
        cnt += (a[i] + mid - 1) / mid;
    }
    return cnt <= m;
}  
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    file("betue");
    cin>>m>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int l = 1;
    int r = 1e9;
    int res = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            res = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << res;
    return 0;
}
