#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        string alpha;
        string digits;
        bool flag = true;
        for (int i = 0; i < s.size(); i++) {
            if (isalpha(s[i])) {
                if (isupper(s[i])) {
                    flag = false;
                }
                alpha += s[i];
            } else {
                digits += s[i];
            }
        }
        sort(alpha.begin(), alpha.end());
        sort(digits.begin(), digits.end());
        string total = digits + alpha;
        for (int i = 0; i < n; i++) {
            if (total[i] != s[i]) {
                flag = false;
            }
        }
        if (flag) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}