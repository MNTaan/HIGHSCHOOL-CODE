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
const int maxN = 1e5 + 10;
const int cs = 2e5 + 100;
using namespace std;
struct mtrx
{
    int A[3][3];
    mtrx()
    {
        memset(A, 0x3f, sizeof(A));
        A[0][0] = A[1][1] = A[2][2] = 0;
    }
    mtrx operator+(const mtrx &m)
    {
        mtrx ret;
        memset(ret.A, 0x3f, sizeof(ret.A));
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    ret.A[i][k] = min(A[i][j] + m.A[j][k], ret.A[i][k]);
                }
            }
        }
        return ret;
    }
};
mtrx M[maxN];
struct smt
{
    int lim;
    mtrx tree[cs];
    void init(int n)
    {
        for (lim = 1; lim <= n; lim <<= 1)
            ;
        for (int i = 0; i < n; i++)
            tree[i + lim] = M[i];
        for (int i = lim - 1; i; i--)
            tree[i] = tree[2 * i] + tree[2 * i + 1];
    }
    void upd(int x, mtrx v)
    {
        x += lim;
        tree[x] = v;
        while (x > 1)
        {
            x >>= 1;
            tree[x] = tree[2 * x] + tree[2 * x + 1];
        }
    }
};
smt seg;
vector<ll> calc(vector<ll> W, vector<ll> A, vector<ll> B, vector<ll> E)
{
    ll n = W.size();
    vector<array<ll, 3>> a(n);
    for (int i = 0; i < n; i++)
    {
        a[i] = {W[i], A[i], B[i]};
    }
    sort(a.begin(), a.end());
    vector<array<ll, 3>> events;
    for (int i = 1; i < n; i++)
    {
        events.push_back({a[i][0] - a[i - 1][0], i - 1, i});
        if (i > 1)
            events.push_back({a[i][0] - a[i - 2][0], i - 2, i});
    }
    sort(events.begin(), events.end());

    for (int i = 0; i < n; i++)
    {
        memset(M[i].A, 0x3f, sizeof(M[i].A));
        M[i].A[0][0] = a[i][1];
        M[i].A[1][0] = M[i].A[2][1] = 0;
    }
    vector<array<ll, 2>> ans;
    seg.init(n);
    ans.push_back({0, seg.tree[1].A[0][0]});
    for (auto &[v, l, r] : events)
    {
        if (r - l == 2)
            M[l].A[0][2] = a[l][2] + a[r][2] + a[l + 1][1];
        else
            M[l].A[0][1] = a[l][2] + a[r][2];
        seg.upd(l, M[l]);
        ans.push_back({v, seg.tree[1].A[0][0]});
    }
    vector<ll> res(E.size());
    vector<array<ll, 2>> queries;
    for (int i = 0; i < E.size(); i++)
    {
        queries.push_back({E[i], i});
    }
    sort(queries.begin(), queries.end());
    int j = 0;
    for (auto &[k, idx] : queries)
    {
        while (j < ans.size() && ans[j][0] <= k)
            j++;
        res[idx] = ans[j - 1][1];
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    ll n, q;
    string s;
    cin >> s;
    cin >> n;
    vector<ll> W(n), A(n), B(n);
    for (int i = 0; i < n; i++)
        cin >> W[i] >> A[i] >> B[i];

    cin >> q;
    vector<ll> E(q);
    for (int i = 0; i < q; i++)
        cin >> E[i];
    vector<ll> ans = calc(W, A, B, E);
    cout << "4FBwMMwcdlgPodEtp0owUlxQgA5SuIlq\n";
    if (ans.size() > 0)
        cout << "OK\n";
    for (ll i : ans)
        cout << i << endl;

    return 0;
}
