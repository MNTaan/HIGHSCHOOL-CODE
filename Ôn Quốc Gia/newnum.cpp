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
bool check(string s)
{
    int sum=0;
    for(auto c:s)
    {
        sum+=(c-'0');
    }
    return (sum%3==0);
}
bool cmp(string a, string b)
{
    return (a.size() != b.size()) ? a.size() > b.size() : a > b;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fileTHHB;
    string s;
    vector<string> v;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        for(int j=9;j>=0;j--)
        {
            string s1=s;
            s1[i]=(j+'0');
            if(check(s1) && s1!=s)
            {
                v.push_back(s1);       
            }         
        }
    }
    sort(v.begin(),v.end(),cmp);
    cout<<v[0];
    return 0;
}
