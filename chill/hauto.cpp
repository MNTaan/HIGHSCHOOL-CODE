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
const int maxN = 2e5 + 10;
using namespace std;
stack<string> st;
vector<string> ss;
string getString(char x)
{
    string s(1, x);
    return s;
}

int compare(string x)
{
    if (x == "+" || x == "-")
        return 1;
    else if (x == "x" || x == "/")
        return 2;
    else
        return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    string s;
    getline(cin, s);
    s = s + ")";
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' || s[i] == ')' || s[i] == '+' || s[i] == '-' || s[i] == 'x' || s[i] == '/')
        {
            string tmp = getString(s[i]);
            ss.push_back(tmp);
        }
        else
        {
            string tmp = "";
            while (s[i] != '(' && s[i] != ')' && s[i] != '+' && s[i] != '-' && s[i] != 'x' && s[i] != '/')
            {
                tmp = tmp + getString(s[i]);
                i++;
            }
            ss.push_back(tmp);
            i--;
        }
    }
    ss.pop_back();
    string res = "";
    for (int i = 0; i < ss.size(); i++)
    {
        if (ss[i] != "(" && ss[i] != ")" && ss[i] != "+" && ss[i] != "-" && ss[i] != "x" && ss[i] != "/")
        {
            cout << ss[i] << " ";
        }
        else if (ss[i] == "(")
        {
            st.push(ss[i]);
        }
        else if (ss[i] == ")")
        {
            while (!st.empty() && st.top() != "(")
            {
                if (st.top() == "x")
                    cout << "* ";
                else
                    cout << st.top() << " ";
                st.pop();
            }
            st.pop();
        }
        else
        {
            while (!st.empty() && compare(ss[i]) <= compare(st.top()))
            {
                if (st.top() == "x")
                    cout << "* ";
                else
                    cout << st.top() << " ";
                st.pop();
            }
            st.push(ss[i]);
        }
    }

    while (!st.empty())
    {
        if (st.top() == "x")
            cout << "* ";
        else
            cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
}
