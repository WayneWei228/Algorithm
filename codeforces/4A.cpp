#include <cstdio>
#include <iostream>
using namespace std;

int main() {
    int a;
    cin >> a;
    
    for (int i = 2; i < a; i += 2) {
        if ((a - i) % 2 == 0) {
            cout << "YES" << '\n';
            return 0;
        }
    }
    cout << "NO" << '\n';
};