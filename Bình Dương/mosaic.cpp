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
const int maxN = 200000 + 5;
using namespace std;
int d0[3][maxN], d1[3][maxN];
ll ps0[3][maxN], ps1[3][maxN];
ll psi0[3][maxN], psi1[3][maxN];
vector<long long> mosaic(vector<ll> X, vector<ll> Y, vector<ll> T, vector<ll> B, vector<ll> L, vector<ll> R)
{
    while (X.size() < 3)
        X.push_back(0);
    while (Y.size() < 3)
        Y.push_back(0);
    for (int i = 0; i < X.size(); i++)
        d0[0][i] = X[i];
    for (int i = 0; i < Y.size(); i++)
        d1[0][i] = Y[i];
    for (int i = 1; i < 3; i++)
    {
        d0[i][0] = Y[i];
        d1[i][0] = X[i];
        for (int j = 1; j < X.size(); j++)
        {
            d0[i][j] = (1 - d0[i - 1][j]) && (1 - d0[i][j - 1]);
        }
        for (int j = 1; j < Y.size(); j++)
        {
            d1[i][j] = (1 - d1[i - 1][j]) && (1 - d1[i][j - 1]);
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < maxN; j++)
        {
            ps0[i][j] = (j ? ps0[i][j - 1] : 0) + d0[i][j];
            ps1[i][j] = (j ? ps1[i][j - 1] : 0) + d1[i][j];
            psi0[i][j] = (j ? psi0[i][j - 1] : 0) + d0[i][j] * j;
            psi1[i][j] = (j ? psi1[i][j - 1] : 0) + d1[i][j] * j;
        }
    }
    vector<ll> ans(T.size());
    auto f = [&](int x, int y)
    {
        int d = min(x, y) - 2;
        if (d >= 0)
        {
            x -= d;
            y -= d;
        }
        if (x <= 2)
            return d0[x][y];
        return d1[y][x];
    };
    auto h = [&](int *d0, int *d1, ll *s0, ll *s1, ll *si0, ll *si1, int x, int y)
    {
        ll ans = 0;
        ans -= (si1[x - 1] - si1[x - y + 2]);
        ans -= (si0[y - 1] - si0[1]);
        ans += 1ll * (y - 2) * (s1[x - y + 2] - s1[2]);
        ans += 1ll * y * (s0[y - 1] - s0[1]);
        ans += 1ll * x * (s1[x - 1] - s1[x - y + 2]);
        return ans;
    };
    auto g = [&](int x, int y)
    {
        if (x < 0 || y < 0)
            return 0ll;
        ll ans = 0;
        if (x <= 2)
        {
            for (int i = 0; i <= x; i++)
                ans += ps0[i][y];
            return ans;
        }
        if (y <= 2)
        {
            for (int i = 0; i <= y; i++)
                ans += ps1[i][x];
            return ans;
        }
        for (int i = 0; i <= 2; i++)
            ans += ps0[i][y];
        for (int i = 0; i <= 2; i++)
            ans += ps1[i][x] - ps1[i][2];
        if (x >= y)
        {
            ans += h(d0[2], d1[2], ps0[2], ps1[2], psi0[2], psi1[2], x, y);
        }
        else
        {
            ans += h(d1[2], d0[2], ps1[2], ps0[2], psi1[2], psi0[2], y, x);
        }
        return ans;
    };
    for (int i = 0; i < T.size(); i++)
    {
        ans[i] += g(B[i], R[i]) - g(B[i], L[i] - 1) - g(T[i] - 1, R[i]) + g(T[i] - 1, L[i] - 1);
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    ll n;
    string s;
    cin >> s;
    cin >> n;
    vector<ll> X(n), Y(n), T(n), B(n), L(n), R(n);
    X.resize(n);
    Y.resize(n);
    T.resize(n);
    B.resize(n);
    L.resize(n);
    R.resize(n);
    for (int i = 0; i < n; i++)
        cin >> X[i];
    for (int i = 0; i < n; i++)
        cin >> Y[i];
    ll q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> T[i] >> B[i] >> L[i] >> R[i];
    }
    vector<long long> res = mosaic(X, Y, T, B, L, R);
    cout << "Wm5rkGNobnYjFI7TIY17RAm6FAQ2LlO9\nOK\n";
    for (int i = 0; i < q; i++)
        cout << res[i] << "\n";
    return 0;
}
