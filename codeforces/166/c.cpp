#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n, m;
        cin >> n >> m;
        int arr[n + m + 1][2];
        for (int i = 0; i < n + m + 1; i++) {
            cin >> arr[i][0];
        }
        for (int i = 0; i < n + m + 1; i++) {
            cin >> arr[i][1];
        }
        int p = n;
        int t = m;
        int i = 0;
        int total = 0;
        while (p + t > 0) {
            if (arr[i][0] > arr[i][1] && p > 0) {
                p--;
                total += arr[i][0];
            } else {
                total += arr[i][1];
                t--;
            }
        }

    }
    return 0;
}