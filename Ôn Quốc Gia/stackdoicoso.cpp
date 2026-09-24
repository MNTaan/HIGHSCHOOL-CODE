#include <bits/stdc++.h>

using namespace std;
unsigned long long n;
unsigned long long s;
vector<int>::reverse_iterator rit;
vector<int> a;
void nhiphan(unsigned long long s)
{
    if (s == 0)
        a.push_back(0);
    while (s)
    {
        int x = s % 2;
        a.push_back(x);
        s = s / 2;
    }
}
int main()
{
    freopen("Stackdoicoso.inp", "r", stdin);
    freopen("Stackdoicoso.out", "w", stdout);
    cin >> n;
    nhiphan(n);
    for (rit = a.rbegin(); rit != a.rend(); rit++)
        cout << *rit;
    return 0;
}
