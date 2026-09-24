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
const int maxN = 100000 + 10;
using namespace std;
ll a[maxN];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    file("hangcay");
    ll n;
    set<ll> st;
    set<ll>::iterator it;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        st.insert(a[i]);
        it = st.lower_bound(a[i]);
        it++;
        if (it != st.end())
            st.erase(it);
    }
    cout << st.size();
    return 0;
}
