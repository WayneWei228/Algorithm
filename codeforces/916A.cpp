#include <iostream>
#include <cstdio>
#include <string>
using namespace std;


struct Solution {

    int N;
    string s;
    int arr[26];
    int cnt = 0;

    void Solve() {
        cin >> N;
        cin >> s;
        for (int i = 0; i < s.size(); i++) {
            arr[s[i] - 'A']++;
        }    
        for (int i = 0; i < 26; i++) {
            if (arr[i] >= i + 1) {
                cnt++;
            }
        }     
        cout << cnt << endl;
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) Solution().Solve();
    return 0;
}