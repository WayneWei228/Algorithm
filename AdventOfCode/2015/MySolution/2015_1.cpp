#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

int main() {
    freopen("2015_1.txt", "r", stdin);
    string a = "";
    cin >> a;
    int ans = 0;

    // puzzle 1

    // for(int i = 0; i < a.size(); i++) {
    //     if(a[i] == '(') {
    //         ans++;
    //     } else {
    //         ans--;
    //     }
    // }


    // puzzle 2
    for(int i = 0; i < a.size(); i++) {
        if(a[i] == '(') {
            ans++;
        } else {
            ans--;
        }
        if(ans < 0) {
            ans = i + 1;
            break;
        }
    }
    // cout << a << endl;
    cout << ans << endl;
    return 0;
    fclose(stdin);
}