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
struct Piece
{
    char type;
    int x, y;
};
Piece pieces[maxN];
bool ok = false;
bool is_check(int king_x, int king_y, int n)
{
    int d[8][2] = {
        {INF, -1}, {INF, -1}, {INF, -1}, {INF, -1}, {INF, -1}, {INF, -1}, {INF, -1}, {INF, -1}};

    for (int i = 0; i < n; ++i)
    {
        int dx = pieces[i].x - king_x;
        int dy = pieces[i].y - king_y;

        if (dx == 0)
        {
            if (dy > 0 && dy < d[0][0])
                d[0][0] = dy, d[0][1] = i;
            else if (dy < 0 && -dy < d[1][0])
                d[1][0] = -dy, d[1][1] = i;
        }
        else if (dy == 0)
        {
            if (dx > 0 && dx < d[2][0])
                d[2][0] = dx, d[2][1] = i;
            else if (dx < 0 && -dx < d[3][0])
                d[3][0] = -dx, d[3][1] = i;
        }
        else if (abs(dx) == abs(dy))
        {
            if (dx > 0 && dy > 0 && dx < d[4][0])
                d[4][0] = dx, d[4][1] = i;
            else if (dx > 0 && dy < 0 && dx < d[5][0])
                d[5][0] = dx, d[5][1] = i;
            else if (dx < 0 && dy > 0 && -dx < d[6][0])
                d[6][0] = -dx, d[6][1] = i;
            else if (dx < 0 && dy < 0 && -dx < d[7][0])
                d[7][0] = -dx, d[7][1] = i;
        }
    }

    for (int i = 0; i < 8; i++)
    {
        if (d[i][1] == -1)
            continue;
        char type = pieces[d[i][1]].type;

        if ((i < 4 && (type == 'R' || type == 'Q')) ||
            (i >= 4 && (type == 'B' || type == 'Q')))
        {
            return true;
        }
    }
    return false;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    int n;
    while (n != -1)
    {
        cin >> n;
        if (n == -1)
        {
            ok = true;
            return 0;
        }

        int king_x, king_y;
        cin >> king_x >> king_y;

        for (int i = 0; i < n; ++i)
        {
            cin >> pieces[i].type >> pieces[i].x >> pieces[i].y;
        }

        cout << (is_check(king_x, king_y, n) ? "YES\n" : "NO\n");
    }
    return 0;
}
