#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n; 
        cin >> n;
        long long arr[n];
        long long c = 0;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        for (int i = 0; i < n; i++) {
            if (arr[i] > 0) {
                c = abs(c);
            }
            c += arr[i];

        }
        c = abs(c);
        cout << c << endl;
    }
    return 0;
}