/**
 *    author:  wayne
 *    created: 2024-08-13 00:24:46
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, T, A;
    cin >> N >> T >> A;
    int larger = max(T, A);
    if (larger > N / 2) { // larger >= (N + 1) / 2
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}