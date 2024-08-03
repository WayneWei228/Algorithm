#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;



int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n, m;
        cin >> n >> m;
        vector<int> arr;
        arr.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        int mx = 0;
        int cur = arr[0];
        int cur_sum = max(0, m - arr[0]);
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] - cur > 1) {
                cur = arr[i];
                cur_sum = 0;
            } else {
                
            }
        }
    }


    return 0;
}