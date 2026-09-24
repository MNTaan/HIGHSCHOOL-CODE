#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
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
const int maxN = 200000 + 10;
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    ll n, a;
    set<int> s1, s2;
    set<int>::iterator it1, it2;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        s1.insert(a);
        s2.insert(-1 * a);
        it1 = s1.lower_bound(a - 1);
        it2 = s2.lower_bound((-1 * a) - 1);
        it1++;
        it2++;
        if (it1 != s1.end())
            s1.erase(it1);
        if (it2 != s2.end())
            s2.erase(it2);
        cout << s1.size() + s2.size() - 1 << " ";
    }
    return 0;
}
