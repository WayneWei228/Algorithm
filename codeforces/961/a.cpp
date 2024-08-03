#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main() {
    int tt;
    cin >> tt;
    while(tt--) {
        int n, k;
        cin >> n >> k;
        if (k == 0) {
            cout << "0" << endl;
            continue;
        }
        if (k <= n && k != 0) {
            cout << "1" << endl;
            continue;
        }
        k -= n;
        int cnt = 1;
        int sub = n - 1;
        int sub_cnt = 0;
        while (k > 0) {
            k -= sub;
            sub_cnt += 1;
            if (sub_cnt == 2) {
                sub_cnt = 0;
                sub -= 1;
            }
            cnt += 1;
        }
        cout << cnt << endl;
    }   
    return 0;
}