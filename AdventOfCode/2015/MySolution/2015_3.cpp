#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

char Buffer[700001];
bool grid[10001][10001];

struct Solution {
    string S;



    void Solve() {
        int ans = 1;
        scanf("%s", Buffer);
        S = Buffer;
        // cout << S << endl;
        // cout << S.size() << endl;
        int x1 = 0, y1 = 0;
        int x2 = 0, y2 = 0;
        grid[0][0] = 1;
        for(int i = 0; i < S.size(); i++) {
            if(i % 2 == 0) {
                if(S[i] == '^') {
                    if(!grid[x1][++y1]) {
                        ans++;
                    }
                }else if(S[i] == '<') {
                    if(!grid[--x1][y1] == 1) {
                        ans++;
                    } 
                } else if(S[i] == '>') {
                    if(!grid[++x1][y1] == 1) {
                        ans++;
                    }
                } else {
                    if(!grid[x1][--y1] == 1) {
                        ans++;
                    }
                }
                // cout << x << " " << y << endl;
                grid[x1][y1] = 1;
            } else {
                if(S[i] == '^') {
                    if(!grid[x2][++y2]) {
                        ans++;
                    }
                }else if(S[i] == '<') {
                    if(!grid[--x2][y2] == 1) {
                        ans++;
                    } 
                } else if(S[i] == '>') {
                    if(!grid[++x2][y2] == 1) {
                        ans++;
                    }
                } else {
                    if(!grid[x2][--y2] == 1) {
                        ans++;
                    }
                }
                // cout << x << " " << y << endl;
                grid[x2][y2] = 1;
            }
        }
        cout << ans << endl;
        
    }
};

int main() {
    freopen("2015_3.txt", "r", stdin);
    Solution().Solve();
    return 0;
    fclose(stdin);
}