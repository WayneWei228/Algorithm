#include <cstdio>
#include <string>
#include <iostream>
#include <cctype>
#include <queue>
using namespace std;

char Buffer[300000];
struct Solution {
    queue<char> V;
    int ans1 = 0;
    int ans2 = 0;

    string Fix(const string& input) {
        string s = input;
        // :"red"
        int i = 0;
        while (i < s.size() - 5){
            if(s[i] == ':' && s[i + 1] == '"' && s[i + 2] == 'r' && s[i + 3] == 'e' && s[i + 4] == 'd' && s[i + 5] == '"') {
                int left = i;
                int right = i;
                int cntL = 0;
                int cntR = 0;
                while (left >= 0) {
                    if(s[left] == '}') {
                        cntL++;
                    }
                    if(s[left] == '{') {
                        cntL--;
                    }
                    if(cntL == -1) {
                        break;
                    } 
                    left--;
                }
                while(right < s.size()) {
                    if(s[right] == '{') {
                        cntR++;
                    }
                    if(s[right] == '}') {
                        cntR--;
                    }
                    if(cntR == -1) {
                        right += 2; // 加 2 是为了把逗号也去掉，更好看
                        break;
                    }
                    right++;
                }
                s.erase(s.begin() + left, s.begin() + right);
                i = left;
            }
            i++;
        }
        return s;
    }

    int FindSum(const string& input) {
        int num = 0;
        for(int i = 0; i < input.size(); i++) {
            if(input[i] == '-' || isdigit(input[i])) {
                V.push(input[i]);
            } else {
                if(!V.empty()) {
                    string temp = "";
                    while(!V.empty()) {
                        temp += V.front();
                        V.pop();
                    }
                    num += stol(temp);
                }
            }
        }
        return num;
    }

    void Solve() {
        scanf("%s", Buffer);
        string s = Buffer;
        ans1 += FindSum(s);
        cout << ans1 << endl;

        string s2 = Fix(s);
        for(int i = 0; i < 200; i++) {
            s2 = Fix(s2);
        }
        ans2 += FindSum(s2);
        cout << ans2 << endl;
        cout << s2 << endl;
    }
};

int main() {
    freopen("2015_12.txt", "r", stdin);
    freopen("2015_12_out.txt", "w", stdout);
    Solution().Solve();
    fclose(stdin);
    fclose(stdout);
    return 0;
}