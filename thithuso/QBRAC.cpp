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
const int maxN = 200000 + 10;
const int INF = 1e18;
const int MOD = 0;
using namespace std;
struct node
{
    int open, close;
    bool flip;
};

vector<node> Tree;
string S;
int n, q;

node merge(node left, node right)
{
    int matched = min(left.open, right.close);
    return {
        left.open + right.open - matched,
        left.close + right.close - matched,
        false};
}

void build(int id, int l, int r)
{
    if (l == r)
    {
        Tree[id] = {S[l] == '(', S[l] == ')', false};
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    Tree[id] = merge(Tree[id * 2], Tree[id * 2 + 1]);
}

void push(int id, int l, int r)
{
    if (!Tree[id].flip)
        return;
    swap(Tree[id].open, Tree[id].close);
    if (l != r)
    {
        Tree[id * 2].flip ^= true;
        Tree[id * 2 + 1].flip ^= true;
    }
    Tree[id].flip = false;
}

void update(int id, int l, int r, int L, int H, char c)
{
    push(id, l, r);
    if (l > H || r < L)
        return;
    if (l >= L && r <= H)
    {
        if (c == '(')
            Tree[id] = {r - l + 1, 0, false};
        if (c == ')')
            Tree[id] = {0, r - l + 1, false};
        Tree[id].flip = false;
        return;
    }
    int mid = (l + r) / 2;
    update(id * 2, l, mid, L, H, c);
    update(id * 2 + 1, mid + 1, r, L, H, c);
    Tree[id] = merge(Tree[id * 2], Tree[id * 2 + 1]);
}

void flip(int id, int l, int r, int L, int H)
{
    push(id, l, r);
    if (l > H || r < L)
        return;
    if (l >= L && r <= H)
    {
        Tree[id].flip ^= true;
        push(id, l, r);
        return;
    }
    int mid = (l + r) / 2;
    flip(id * 2, l, mid, L, H);
    flip(id * 2 + 1, mid + 1, r, L, H);
    Tree[id] = merge(Tree[id * 2], Tree[id * 2 + 1]);
}

node query(int id, int l, int r, int L, int H)
{
    push(id, l, r);
    if (l > H || r < L)
        return {0, 0, false};
    if (l >= L && r <= H)
        return Tree[id];
    int mid = (l + r) / 2;
    node left = query(id * 2, l, mid, L, H);
    node right = query(id * 2 + 1, mid + 1, r, L, H);
    return merge(left, right);
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);t
    file("QBRAC");

    cin >> n >> q;
    cin >> S;
    Tree.resize(4 * n);
    build(1, 0, n - 1);

    while (q--)
    {
        int L, H;
        char c;
        cin >> L >> H >> c;
        L -= 1;
        H -= 1;
        if (c == '?')
        {
            node res = query(1, 0, n - 1, L, H);
            cout << (res.open == 0 && res.close == 0 ? "yes\n" : "no\n");
        }
        else if (c == '-')
            flip(1, 0, n - 1, L, H);
        else
            update(1, 0, n - 1, L, H, c);
    }
    return 0;
}
