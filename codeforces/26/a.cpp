#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        if (arr[0] == arr[n - 1]) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            for (int i = 0; i < n; i++) {
                cout << ((i == 1) ? "B" : "R"); 
            }
            cout << endl;
        }
    }
    return 0;
}