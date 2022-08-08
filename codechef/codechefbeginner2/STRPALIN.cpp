#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;


/*

3
abc
abc

a
b

abba
baab
*/

int main() {
    int T;
    cin >> T;
    for(int i = 0; i < T; i++) {
        string a, b;
        cin >> a;
        cin >> b;
        vector<bool> arr;
        arr.resize(26);
        for(int i = 0; i < a.size(); i++) {
            arr[a[i] - 'a'] = true;
        }
        bool ans = false;
        for(int i = 0; i < b.size(); i++) {
            if(arr[b[i] - 'a']) {
                ans = true;
                break;
            }
        }
        if (ans) {
            cout << "Yes" << '\n';
        } else
        {
            cout << "No" << '\n';
        }
        // cout << (ans ? "Yes\n" : "No\n");
    }
    return 0;    
}