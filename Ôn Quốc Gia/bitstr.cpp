#include <bits/stdc++.h>
#define name "TASK"
#define int long long
const int N = 2e5 + 69;
using namespace std;

int n, k, L[N], R[N], a[N], sz[N];
string s;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if (fopen(name ".inp", "r"))
    {
        freopen(name ".inp", "r", stdin);
        freopen(name ".out", "w", stdout);
    }
    cin >> n >> k >> s;
    int nn = 0;
    for (int l = 0, r = 0; l < n; l = r)
    {
        while (r < n && s[r] == s[l])
            r++;
        nn++;
        sz[nn] = r - l;
    }
    int ans = N;
    for (int st : {1, 2})
        for (int ed : {nn, nn - 1})
        {
            int res = (st == 2 ? sz[1] : 0) + (ed == nn - 1 ? sz[nn] : 0);
            set<pair<int, int>> mn;
            for (int i = st; i <= ed; i++)
            {
                L[i] = i - 1;
                R[i] = i + 1;
                a[i] = sz[i];
            }
            L[st] = 0, R[ed] = 0;
            a[st] = a[ed] = N;
            for (int i = st + 1; i < ed; i++)
            {
                mn.insert({a[i], i});
            }
            int num = nn - (st == 2) - (ed == nn - 1);
            while (num > k && !mn.empty())
            {
                auto it = *mn.begin();
                mn.erase(mn.begin());
                num -= 2;
                res += it.first;
                if (L[L[it.second]])
                    mn.erase(mn.find({a[L[it.second]], L[it.second]})), R[L[L[it.second]]] = it.second;

                if (R[R[it.second]])
                    mn.erase(mn.find({a[R[it.second]], R[it.second]})), L[R[R[it.second]]] = it.second;

                a[it.second] = a[L[it.second]] + a[R[it.second]] - a[it.second];

                L[it.second] = L[L[it.second]];
                R[it.second] = R[R[it.second]];

                if (L[it.second] && R[it.second])
                    mn.insert({a[it.second], it.second});
            }
            if (num <= k)
                ans = min(ans, res);
        }
    cout << ans;
    return 0;
}
