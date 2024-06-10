#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

bool twolarge(int n) {
    bool can = false;
    for (int i = 5; i <= 9; i++) {
        if (n - i >= 5 && n - i <= 9) {
            can = true;
        }
    }
    return can;
}

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        string number;
        cin >> number;
        if (number[0] != '1') {
            cout << "NO" << endl;
            continue;
        }
        bool can = true;
        int n = number.size();
        int carry_on = 0;
        for (int i = n - 1; i > 0; i--) {
            int theother = number[i] - '0' - carry_on + 10;
            if (twolarge(theother)) {
                carry_on = 1;
            } else {
                can = false;
            }
        }
        cout << ((can) ? "YES" : "NO") << endl;
    }
    return 0;
}