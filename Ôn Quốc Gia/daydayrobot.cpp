#include <bits/stdc++.h>
#define x first
#define y second
#define file(name)                    \
    freopen(name ".inp", "r", stdin); \
    freopen(name ".out", "w", stdout);
#define fileTHHB                      \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout)
using namespace std;
const int N = 503;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
bool vis[N][N][4];
char grid[N][N];
int dp[10][10][N][N], n, w, h;
int tot = 0, l, r, id[N * N];
pair<int, int> q1[N * N], q2[N * N], to[N][N][4], tt;
pair<int, int> dfs(int x, int y, int d)
{ // recursion to find where (x,y) goes after 1 push
    if (vis[x][y][d])
        return to[x][y][d];
    vis[x][y][d] = true;
    if (grid[x][y] == 'A')
        (++d) &= 3;
    if (grid[x][y] == 'C')
        (--d) &= 3;
    if (grid[x + dx[d]][y + dy[d]] == 'x')
        return {x, y};
    else
        return to[x + dx[d]][y + dy[d]][d] = dfs(x + dx[d], y + dy[d], d);
}
template <typename T>
void check_min(T &a, T b)
{
    if (b < a)
        a = b;
}
template <typename T>
void check_max(T &a, T b)
{
    if (b > a)
        a = b;
}
int c[N * N * 20];
void BFS()
{
    int mx = 0, num;
    for (int i = 1; i <= tot; ++i)
    {
        if ((num = dp[l][r][q1[i].x][q1[i].y]) != 1010580540)
        {
            mx = max(mx, num);
        }
    }
    memset(c, 0, sizeof(int) * (mx + 2));
    for (int i = 1; i <= tot; ++i)
    {
        num = dp[l][r][q1[i].x][q1[i].y];
        if (num != 1010580540)
            ++c[num];
        else
            ++c[mx + 1];
    }
    for (int i = 1; i <= mx + 1; ++i)
        c[i] += c[i - 1];
    for (int i = tot; i >= 1; --i)
    {
        num = dp[l][r][q1[i].x][q1[i].y];
        if (num == 1010580540)
            num = mx + 1;
        id[c[num]--] = i; // what is id?
    }
    int head = 1, tail = 0, tmp = 1, x, y, x2, y2;
    while (head <= tail || tmp <= tot)
    {
        x = q2[head].x;
        y = q2[head].y;
        x2 = q1[id[tmp]].x;
        y2 = q1[id[tmp]].y;
        if (head <= tail && tmp <= tot && dp[l][r][x][y] < dp[l][r][x2][y2] || tmp > tot)
            ++head;
        else
            ++tmp, x = x2, y = y2;
        for (int d = 0; d < 4; ++d)
        {
            tt = to[x][y][d];
            if (tt.x == 0)
                continue;
            if (dp[l][r][tt.x][tt.y] > dp[l][r][x][y] + 1)
            { // we update this when the other one is smaller, because there is a second way to get it
                dp[l][r][tt.x][tt.y] = dp[l][r][x][y] + 1;
                q2[++tail] = tt;
            }
        }
    }
}

int main()
{
    fileTHHB;
    cin >> n >> w >> h;
    memset(dp, 60, sizeof(dp));
    for (int i = 1; i <= h; ++i)
        cin >> grid[i] + 1;
    for (int i = 1; i <= h; ++i)
        grid[i][0] = grid[i][w + 1] = 'x';
    for (int i = 1; i <= w; ++i)
        grid[0][i] = grid[h + 1][i] = 'x';
    for (int i = 1; i <= h; ++i)
        for (int j = 1; j <= w; ++j)
            if (grid[i][j] != 'x')
                for (int dt = 0; dt < 4; ++dt)
                    to[i][j][dt] = dfs(i, j, dt);

    for (int i = 1; i <= h; ++i)
        for (int j = 1; j <= w; ++j)
            q1[++tot] = make_pair(i, j);

    bool flag;
    for (int i = n; i >= 1; --i)
    {
        flag = false;
        for (int ii = 1; ii <= h; ++ii)
        {
            for (int jj = 1; jj <= w; ++jj)
                if (grid[ii][jj] == '0' + i)
                {
                    dp[i][i][ii][jj] = 0;
                    flag = true;
                    break;
                }
            if (flag)
                break;
        }
        l = r = i;
        BFS();
        for (int j = i + 1; j <= n; ++j)
        {
            for (int k = i; k < j; ++k)
                for (int ii = 1; ii <= h; ++ii)
                    for (int jj = 1; jj <= w; ++jj)
                        dp[i][j][ii][jj] = min(dp[i][j][ii][jj], dp[i][k][ii][jj] + dp[k + 1][j][ii][jj]);
            l = i;
            r = j;
            BFS();
        }
    }

    int ans = 0x7fffffff;
    for (int i = 1; i <= h; ++i)
        for (int j = 1; j <= w; ++j)
            ans = min(ans, dp[1][n][i][j]);
    cout << (ans == 1010580540 ? -1 : ans) << "\n";
    return 0;
}