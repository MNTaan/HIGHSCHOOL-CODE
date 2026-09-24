#include <bits/stdc++.h>
using namespace std;
using lli = int64_t;

int numVertex, numRoad;
int LIM[2];
const lli INF_64 = 0x3f3f3f3f3f3f3f3f;
const int MAX_N = 1e5 + 5;

vector<pair<int, int>> graph[MAX_N][2];

lli dist[MAX_N][4][4][2];
template <class T>
using MinHeap = priority_queue<T, vector<T>, greater<T>>;

struct Data
{
    lli cost;
    int pos, used, len, reversed;

    Data(int u, int _used, int _len, int rev)
    {
        pos = u;
        used = _used;
        len = _len;
        reversed = rev;
        cost = dist[pos][used][len][reversed];
    }
    bool operator<(const Data &other) const
    {
        return cost > other.cost;
    }
};

bool minimise(lli &x, lli y)
{
    if (x > y)
        return x = y, true;
    return false;
}

priority_queue<Data> heap;
void add_value(int v, int used, int len, int reversed, lli val)
{
    if (minimise(dist[v][used][len][reversed], val))
        heap.emplace(v, used, len, reversed);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
freopen("rescue.inp","r",stdin);
freopen("rescue.out","w",stdout);
    cin >> numVertex >> numRoad >> LIM[0] >> LIM[1];

    for (int i = 1; i <= numRoad; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][0].emplace_back(v, w);
        graph[v][1].emplace_back(u, w);
    }
    memset(dist, 0x3f, sizeof dist);

    dist[1][0][0][0] = 0;
    heap.emplace(1, 0, 0, 0);

    while (not heap.empty())
    {
        Data top = heap.top();
        heap.pop();
        if (top.cost > dist[top.pos][top.used][top.len][top.reversed])
            continue;

        if (not top.reversed)
            add_value(top.pos, 0, 0, 1, top.cost);
        for (pair<int, int> &E : graph[top.pos][top.reversed])
        {
            int v, w;
            tie(v, w) = E;

            int new_length = top.reversed ? min(top.len + 1, LIM[1]) : 0;
            add_value(v, top.used, new_length, top.reversed, top.cost + w);

            lli real_cost = top.cost + 2 * w * top.reversed;
            if (top.used < LIM[top.reversed])
                add_value(v, top.used + 1, new_length, top.reversed, real_cost);
        }
    }

    for (int i = 2; i <= numVertex; ++i)
    {
        lli ans = INF_64;
        for (int used = 0; used <= LIM[1]; ++used)
            minimise(ans, dist[i][used][used][1]);

        if (ans == INF_64)
            cout << "-1 ";
        else
            cout << ans << ' ';
    }
    return 0;
}