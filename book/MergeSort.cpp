#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
vector<int> arr(10);
vector<int> arr2(10);

void MergeSort(int l, int r) {
    if(l == r) return;
    int mid = (l + r) / 2;
    MergeSort(l, mid);
    MergeSort(mid + 1, r);
    int lp = l, rp = mid + 1, s = 0;
    // lp: [l, mid] 区间取到了lp, rp:[mid + 1, r]区间取到了rp;
    // s: 选出的数的个数;
    while(lp <= mid && rp <= r) {
        if(arr[lp] < arr[rp]) arr2[s++] = arr[lp++];
        else arr2[s++] = arr[rp++];
    }
    while(lp <= mid) {
        arr2[s++] = arr[lp++];
    }
    while(rp <= r) {
        arr2[s++] = arr[rp++];
    }
    int c = 0;
    for(int i = l; i <= r; i++) {
        arr[i] = arr2[c++];
    }

}





int main() {
    for(int i = 0; i < 10; i++) {
        arr[i] = rand() % (100 - 10 + 1) + 10;
        // rand() % (rangeR - rangeL + 1) + rangeL;
        // 随机生成数公式
        cout << arr[i] << " ";
    }
    cout << endl;
    MergeSort(0, 9); 

    for(int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";



    return 0;
}