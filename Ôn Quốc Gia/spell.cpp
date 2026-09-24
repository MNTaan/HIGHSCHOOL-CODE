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
const int maxN = 300+1;
using namespace std;
int n,m,k;
string can;
string s[maxN];
int dx[]={1,0,0,-1};
int dy[]={0,1,-1,0};
int d[maxN][maxN][maxN];
void bfs()
{
    queue<pair<int,pair<int,int>>> q;
    memset(d,-1,sizeof d);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            q.push({0,{i,j}});
            d[0][i][j]=0;
        }
    while(!q.empty())
    {
        int sl=q.front().fi;
        int x=q.front().se.fi;
        int y=q.front().se.se;
        q.pop();
        if(sl==k)
        {
            cout<<d[sl][x][y];
            return;
        }
        for(int i=0;i<=3;i++)
        {
            int x1=x+dx[i];
            int y1=y+dy[i];
            if(x1<1 || x1>n || y1<1 || y1>m)
                continue;
            int sl1=sl;
            if(can[sl1+1]==s[x1][y1])
                sl1++;
            if(d[sl1][x1][y1]<0)
            {
                d[sl1][x1][y1] = d[sl][x][y] + 1;
                q.push({sl1, {x1, y1}});
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    cin>>n>>m>>k;
    cin>>can;
    can=" "+can;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
        s[i]=" "+s[i];
    }
    bfs();
    return 0;
}
