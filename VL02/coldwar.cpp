#include <bits/stdc++.h>
using namespace std;

#define input cin
#define output cout
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define endl '\n'
#define all(v) v.begin(), v.end()
#define mem(a, b) memset(a, b, sizeof(a));
#define bit(u, i) ((u >> i) & 1)
#define mask(i) (1ll << i)
#define vi vector<int>

const int cs = 2e5 + 7;
const int mod = 1e9 + 7;
const int INF = mod;
const int maxN = 2e3 + 7;
const int block_size = 320;
const ll oo = 1e18 + 7;

template <class X, class Y>
bool minimize(X &x, const Y &y)
{
    if (x > y)
    {
        x = y;
        return true;
    }
    else
        return false;
}

template <class X, class Y>
bool maximize(X &x, const Y &y)
{
    if (x < y)
    {
        x = y;
        return true;
    }
    else
        return false;
}

template <class T>
T ABS(const T &x)
{
    return (x < 0 ? -x : x);
}

template <class X, class Y>
void AddMod(X &x, const Y &y)
{
    x += y;
    if (x > mod)
        x -= mod;
}

template <class X, class Y>
void SubMod(X &x, const Y &y)
{
    x -= y;
    if (x < 0)
        x += mod;
}

//

struct Edge
{
    int u, v, w, id;
    Edge() {}
    Edge(int uu, int vv, int ww, int idd)
    {
        u = uu;
        v = vv;
        w = ww;
        id = idd;
    }
};

int n, m;
int typeoftest;
vector<Edge> Canh;

void nhap()
{
    input >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y, z;
        input >> x >> y >> z;
        Canh.push_back(Edge(x, y, z, i));
    }
}

void DectingTest()
{
    if (n <= 200 && m <= 500)
        return typeoftest = 1, void();
    if (m <= n + 100)
        return typeoftest = 2, void();
    int ma = 0;
    for (int i = 0; i < Canh.size(); i++)
    {
        maximize(ma, Canh[i].w);
    }
    if (ma <= 10)
        return typeoftest = 3, void();
    return typeoftest = 4, void();
}

struct subTask1
{

    struct DSU
    {
        int n;
        vi parent;
        vi sz;
        DSU() {}
        void resize(int nn)
        {
            n = nn;
            parent.resize(n + 1);
            sz.resize(n + 1);
            for (int i = 1; i <= n; i++)
            {
                parent[i] = i;
                sz[i] = 1;
            }
        }
        int Find(int u)
        {
            if (u == parent[u])
                return u;
            return parent[u] = Find(parent[u]);
        }
        bool Joint(int a, int b)
        {
            a = Find(a);
            b = Find(b);
            if (a == b)
                return false;
            if (sz[a] < sz[b])
                swap(a, b);
            parent[b] = a;
            sz[a] += sz[b];
            return true;
        }
    };

    vector<Edge> NeedCanh;

    void Kruskal()
    {
        sort(all(NeedCanh), [&](Edge a, Edge b)
             { return a.w < b.w; });
        vector<Edge> MST;
        DSU D;
        ll ans = 0;
        D.resize(n);
        for (auto e : NeedCanh)
        {
            if (MST.size() >= n - 1)
                break;
            if (D.Joint(e.u, e.v))
            {
                ans += e.w;
                MST.push_back(e);
            }
        }
        if (MST.size() == n - 1)
            output << ans << endl;
        else
            output << -1 << endl;
    }

    void Solve()
    {
        for (int i = 0; i < Canh.size(); i++)
        {
            NeedCanh.clear();
            for (int j = 0; j < Canh.size(); j++)
            {
                if (i != j)
                    NeedCanh.push_back(Canh[j]);
            }
            Kruskal();
        }
    }
};

struct subTask2
{

    struct DSU
    {
        int n;
        vi parent;
        vi sz;
        DSU() {}
        void resize(int nn)
        {
            n = nn;
            parent.resize(n + 1);
            sz.resize(n + 1);
            for (int i = 1; i <= n; i++)
            {
                parent[i] = i;
                sz[i] = 1;
            }
        }
        int Find(int u)
        {
            if (u == parent[u])
                return u;
            return parent[u] = Find(parent[u]);
        }
        bool Joint(int a, int b)
        {
            a = Find(a);
            b = Find(b);
            if (a == b)
                return false;
            if (sz[a] < sz[b])
                swap(a, b);
            parent[b] = a;
            sz[a] += sz[b];
            return true;
        }
    };

    vector<Edge> MST;
    vi adj[cs];
    vector<Edge> CanUsed;
    int mark[cs];
    ll ans[cs];
    ll d = 0;

    void Kruskal()
    {
        sort(all(Canh), [&](Edge a, Edge b)
             { return a.w < b.w; });
        DSU D;
        D.resize(n);
        for (int i = 0; i < Canh.size(); i++)
        {
            Edge e = Canh[i];
            if (MST.size() >= n - 1)
                break;
            if (D.Joint(e.u, e.v))
            {
                d += e.w;
                MST.push_back(e);
                mark[i] = 1;
            }
        }
    }

    void init()
    {
        for (int i = 0; i < Canh.size(); i++)
        {
            if (!mark[i])
                CanUsed.push_back(Canh[i]);
        }
        for (auto e : MST)
        {
            adj[e.u].push_back(e.v);
            adj[e.v].push_back(e.u);
        }
    }

    int fin[cs];
    int fout[cs];
    int TimeDFS = 1;
    int parent[cs];

    void DFS(int u, int par)
    {
        fin[u] = TimeDFS++;
        for (auto v : adj[u])
        {
            if (v == par)
                continue;
            parent[v] = u;
            DFS(v, u);
        }
        fout[u] = TimeDFS - 1;
    }

    bool isIn(int u, int v)
    {
        return fin[v] <= fin[u] && fin[u] <= fout[v];
    }

    void Solve()
    {
        Kruskal();
        if (MST.size() < n - 1)
        {
            for (int i = 1; i <= m; i++)
            {
                output << -1 << endl;
            }
            return;
        }
        init();
        DFS(1, 0);
        for (int i = 0; i < Canh.size(); i++)
        {
            int u = Canh[i].u;
            int v = Canh[i].v;
            int w = Canh[i].w;
            int id = Canh[i].id;
            if (!mark[i])
                ans[id] = d;
            else
            {
                ans[id] = LLONG_MAX;
                if (v == parent[u])
                    swap(u, v);
                for (auto e : CanUsed)
                {
                    if (isIn(e.u, v) && !isIn(e.v, v))
                    {
                        minimize(ans[id], d - w + e.w);
                    }
                    if (isIn(e.v, v) && !isIn(e.u, v))
                    {
                        minimize(ans[id], d - w + e.w);
                    }
                }
            }
            if (ans[id] == LLONG_MAX)
                ans[id] = -1;
        }
        for (int i = 1; i <= m; i++)
        {
            output << ans[i] << endl;
        }
    }
};

void Solve()
{
    DectingTest();

    if (typeoftest == 1)
    {
        subTask1 *T = new subTask1();
        T->Solve();
        return;
    }

    if (typeoftest == 2)
    {
        subTask2 *T = new subTask2();
        T->Solve();
        return;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#define TASK "COLDWAR"
    if (fopen(TASK ".inp", "r"))
    {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }
    nhap();
    Solve();
    return 0;
}