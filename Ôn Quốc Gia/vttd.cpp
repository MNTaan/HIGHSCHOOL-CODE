#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define x first
#define y second
#define pii pair<ll, ll>
#define file(name)                    \
    freopen(name ".inp", "r", stdin); \
    freopen(name ".out", "w", stdout);
#define fileTHHB                      \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout)
const int maxN = 200000 + 10;
using namespace std;
pii m, a, b;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    file("VTTD");
    cin >> m.x >> m.y;
    cin >> a.x >> a.y;
    cin >> b.x >> b.y;
    int f = (a.x - b.x) * m.x + (b.x - a.x) * m.y + (a.x * b.y - b.x * a.y);
    if(f==0)
        cout << "M thuoc duong thang AB"<<endl;
    else
        cout << "M khong thuoc duong thang AB"<<endl;
    if(f==0 && min(a.x,b.x)<=m.x && m.x<=max(a.x,b.x) && min(a.y,b.y)<=m.y && m.y<=max(a.y,b.y))
        cout << "M thuoc doan thang AB"<<endl;
    else
        cout << "M khong thuoc doan thang AB"<<endl;
    return 0;
}
