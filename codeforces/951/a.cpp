#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int tt;
    cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int maxterm = 1e9+10;
        for (int i = 0; i < n - 1; i++) {
            maxterm = min(maxterm, max(arr[i], arr[i + 1]));
        }
        cout << maxterm - 1 << endl;
    }
    return 0;
}