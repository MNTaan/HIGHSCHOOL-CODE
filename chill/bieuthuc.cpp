#include <bits/stdc++.h>
#define ll long long
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
using namespace std;
string s;
stack<int> st;
int tinh(int x, int y, string s)
{
    if (s[0] == '+')
        return x + y;
    if (s[0] == '-')
        return x - y;
    if (s[0] == '*')
        return x * y;
    if (s[0] == '/')
        return x / y;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    file("bieuthuc");
    while (cin >> s)
    {
        ll so = 0;
        if (s[0] >= '0' && s[0] <= '9')
        {
            for (int i = 0; i < s.size(); i++)
            {
                so = so * 10 + int(s[i] - '0');
            }
            st.push(so);
        }
        else
        {
            int y = st.top();
            st.pop();
            int x = st.top();
            st.pop();
            int kq = tinh(x, y, s);
            st.push(kq);
        }
    }
    cout << st.top();

    return 0;
}
