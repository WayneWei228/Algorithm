#include <iostream>
#include <cstdio>
#include <bitset>
using namespace std;



int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int x, y;
        cin >> x >> y;
        int z = x ^ y;
        int trailingzeros = z & -z;
        cout << trailingzeros << endl;
    }


    return 0;
}