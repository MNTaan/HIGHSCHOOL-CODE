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
const int maxN = 100000 + 10;
using namespace std;
int n, q, bit[maxN], a[maxN];

int getSum(int p) {
    int idx = p, ans = 0;
    while (idx > 0) {
        ans += bit[idx];
        idx -= (idx & (-idx));
    }
    return ans;
}

void upd(int u, int v) {
    int idx = u;
    while (idx <= n) {
        bit[idx] += v;
        idx += (idx & (-idx));
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    file("BITSUM");
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        upd(i,a[i]);
    }
    cin >> q;

    while(q--){
        int id,u,v;
        cin >> id >> u >> v;
        if(id==0)
        {
            int add = v-a[u];
            a[u] = v;
            upd(u,add);
        }
        else{
            cout << getSum(v)-getSum(u-1) << '\n';
        }
    }
    return 0;
}
