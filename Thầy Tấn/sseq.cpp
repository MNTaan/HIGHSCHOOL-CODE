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
const int maxN = 1e5 + 10;
const int INF = 1e18;
const int MOD = 0;
using namespace std;
template <class X, class Y>
bool minimize(X &a, Y b)
{
    if (a > b)
        return a = b, true;
    return false;
}
template <class X, class Y>
bool maximize(X &a, Y b)
{
    if (a < b)
        return a = b, true;
    return false;
}

const int N = 1e6 + 5;
const int LINF = 2e16 + 33;
struct ss
{
    int l, r, w;
};
bool cmp(ss a, ss b)
{

    return a.l < b.l;
}
int n;
ss a[N];
int pre[N];
pair<int, int> check(int val)
{
    pair<int, int> close_ = {0, 0};
    pair<int, int> open_ = {-LINF, 0};
    for (int i = 0; i <= n; i++)
    {
        maximize(close_, make_pair(open_.fi + pre[i], open_.se));
        maximize(open_, make_pair(close_.fi - pre[i] - val, close_.se - 1));
    }
    close_.se *= -1;
    return close_;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    file("SSEQ");
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].l >> a[i].r >> a[i].w;
    }
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; i++)
        pre[i] = pre[i - 1] + a[i].w;
    int k = 1;
    int l = 0, r = 1e15, res = 0;
    while (l <= r)
    {
        int mid = l + r >> 1;

        pair<int, int> cur = check(mid);

        if (cur.se <= k)
            res = cur.fi + k * mid, r = mid - 1;
        else
            l = mid + 1;
    }

    cout << res;
    return 0;
}
