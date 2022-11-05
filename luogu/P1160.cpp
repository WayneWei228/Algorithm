#include <bits/stdc++.h>
using namespace std;


//  4
//  1 0
//  2 1
//  1 0
//  2
//  3
//  3


int a[100010][3], n, m;
//a[i][1]表示学号为i的同学左边同学的学号
//a[i][2]表示学号为i的同学右边同学的学号
int main() {
    cin >> n;
    memset(a, 0, sizeof(a));
    a[1][0] = 1;
    for(int i = 2; i <= n; i++) {
        int k, p;
        cin >> k >> p;
        if(p == 0) {
            a[a[k][1]][2] = i;
            a[i][1] = a[k][1];
            a[k][1] = a[i][0] = i;
            a[i][2] = a[k][0] = k;
        } else {
           a[a[k][2]][1] = a[i][0] = i;
           a[i][2] = a[k][2];
           a[i][1] = a[k][0] = k;
           a[k][2] = a[i][0] = i;
        }
    }

    // for(int i = 1; i <= n; i++) {
    //     cout << "self " << a[i][0] << " l " << a[i][1] << " r " << a[i][2] << endl;
    // }

    int m;
    cin >> m;
    for(int i = 0; i < m; i++) {
        int c;
        cin >> c;
        if(a[c][0] != 0) {
            a[a[c][1]][2] = a[c][2];
            a[a[c][2]][1] = a[c][1];
            a[c][0] = 0;
        }
    }

    // for(int i = 1; i <= n; i++) {
    //     cout << "self " << a[i][0] << " l " << a[i][1] << " r " << a[i][2] << endl;
    // }
    
    int start;
    for(int i = 1; i <= n; i++) {
        if(a[i][0] != 0 && a[i][1] == 0) {
            start = i;
            break;
        }
    }
    
    cout << a[start][0];
    start = a[start][2];

    while(a[start][0] != 0) {
        cout <<  " " << a[start][0];
        start = a[start][2];
    }

    cout << endl;
}


