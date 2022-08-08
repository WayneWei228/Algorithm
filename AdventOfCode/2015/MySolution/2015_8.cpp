#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <functional>
#include <algorithm>
using namespace std;

char Buffer[100];
/*
""
"abc"
"aaa\"aaa"
"\x27"
*/
struct Solution {
    vector<string> V;
    int cntString = 0;
    int cntMem = 0;
    int cntEncode = 0;
    int countString(const string& input) {
        return input.length();
    }

    int countMem(const string& in) {
        string input = in.substr(1, in.length() - 2);
        int cnt = 0;        
        // cout << "input " << input << endl;
        for(int i = 0; i < input.size();) {
            cnt++;
            if(input[i] == '\\') {
                switch(input[i + 1]) {
                    case '\\':
                        i += 2;
                        break;
                    case '"':
                        i += 2;
                        break;
                    case 'x':
                        i += 4;
                        break;
                } 
            } else {
                i++;
            }
        }
        return cnt;
    }

    int newString(const string& input) {
        int cnt = 6;
        string s = input.substr(1, input.length() - 2);
        for(int i = 0; i < s.size();i++) {
            switch(s[i]) {
                case '\\':
                    cnt += 2;
                    break;
                case '"':
                    cnt += 2;
                    break;
                default :
                    cnt++;
                    break;
            }
        }
        return cnt;
    }

    void Solve() {
        while(true) {
            if(scanf("%[^\n]\n", Buffer) < 1) break;
            V.push_back(Buffer);
        }

        for(int i = 0; i < V.size(); i++) {
            cntString += countString(V[i]);
            cntMem += countMem(V[i]);
            cntEncode += newString(V[i]);          
        }
        int answer1 = cntString - cntMem;
        int answer2 = cntEncode - cntString;
        printf("%d\n", answer1);
        printf("%d\n", answer2);
    }
};

int main() {
    Solution().Solve();
    return 0;
}