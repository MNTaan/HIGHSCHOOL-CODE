#include <bits/stdc++.h>
#define file(name)                      \
    freopen(name ".inp", "r", stdin);   \
    freopen(name ".out", "w", stdout);
using namespace std;

const int N = 1e4+5;

int a[4][4];

bool checkTL(){
    int t1=a[1][1]+a[2][2]+a[3][3];
    int t2=a[3][1]+a[2][2]+a[1][3];
    int d1=a[1][1]+a[1][2]+a[1][3];
    int d2=a[2][1]+a[2][2]+a[2][3];
    int d3=a[3][1]+a[3][2]+a[3][3];
    int n1=a[1][1]+a[2][1]+a[3][1];
    int n2=a[1][2]+a[2][2]+a[3][2];
    int n3=a[1][3]+a[2][3]+a[3][3];
    if(t1==3 || t2==3 || d1==3 || d2==3 || d3==3 ||n1==3 ||n2==3 || n3==3)
        return true;
    return false;
}

bool checkBD(){
    int t1=a[1][1]+a[2][2]+a[3][3];
    int t2=a[3][1]+a[2][2]+a[1][3];
    int d1=a[1][1]+a[1][2]+a[1][3];
    int d2=a[2][1]+a[2][2]+a[2][3];
    int d3=a[3][1]+a[3][2]+a[3][3];
    int n1=a[1][1]+a[2][1]+a[3][1];
    int n2=a[1][2]+a[2][2]+a[3][2];
    int n3=a[1][3]+a[2][3]+a[3][3];
    if(t1==-3 || t2==-3 || d1==-3 || d2==-3 || d3==-3 ||n1==-3 ||n2==-3 || n3==-3)
        return true;
    return false;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    file("caro");
    int CntTL=0, CntBD=0;

    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++){
            char x;
            cin >> x;
            if(x=='X'){
                a[i][j]=1;
                CntTL++;
            }
            if(x=='0'){
                a[i][j]=-1;
                CntBD++;
            }
            if(x=='.')
                a[i][j]=0;
        }
    }

    if(CntBD>CntTL || CntTL-CntBD>=2){
        cout << "invalid";
        return 0;
    }

    if(checkTL()){
        cout << "TL won";
        return 0;
    }

    if(checkBD()){
        cout << "BD won";
        return 0;
    }

    if(CntBD+CntTL==9){
        cout << "draw";
        return 0;
    }

    if(CntTL==CntBD)
        cout << "TL was making a move";
    else
        cout << "BD was making a move";

    return 0;
}