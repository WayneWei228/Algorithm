#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
char Buffer[80];


// 1113222113
// 1211
struct Solution {

    string change(const string& s) {
        int i = 0; 
        char temp = s[0];
        int cnt = 1;
        string ans = "";
        for(int i = 1; i < s.length(); i++) {
            if(temp == s[i]) {
                cnt++;
            } else {
                ans += cnt + '0';
                ans += temp;
                temp = s[i];
                cnt = 1;
            }
        }
        ans += cnt + '0';
        ans += temp;
        return ans;
    }

    void Solve() {
        scanf("%s", Buffer);
        string s = Buffer; 
        string ans1 = s;
        for(int i = 0; i < 40; i++) {
            ans1 = change(ans1);
        }
        string ans2 = ans1;
        for(int i = 0; i < 10; i++) {
            ans2 = change(ans2);
        }
        cout << ans1.length() << endl;
        cout << ans2.length() << endl;
    }

};

int main() {
    Solution().Solve();
    return 0;
}