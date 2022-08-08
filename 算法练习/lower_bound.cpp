#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int b[10];
    int a[10] = {1,2,6,5,4,5,6,7,8,9};
    int maxn=-1;
    
    for(int i = 0; i < 10; i++) {
        maxn=max(maxn,a[i]);
    }    
    cout << maxn << '\n';

    for(int i = 0; i < 10; i++) {
        b[i] = maxn - a[i];
        cout << b[i] << ' ';
    }
    printf("\n");


    // // 找第一个小于等于 num 的数字;
    int num;
    cin >> num;
    int pos;
    pos = lower_bound(b,b+10,num - 1) - b;
    cout << pos << '\n';
    return 0;
}

// 数组所有元素都大于num 找小于等于num 的数 用upper_bound（）
