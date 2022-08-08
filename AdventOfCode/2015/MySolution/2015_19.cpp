#include <cstdio>
#include <vector>
#include <unordered_map>
#include <set>
#include <string>
#include <iostream>
#include <limits>
using namespace std;


/*
Al => ThF
Al => ThRnFAr
B => BCa
B => TiB
B => TiRnFAr
Ca => CaCa
Ca => PB
Ca => PRnFAr

CRnCaCaCaSiRnBPTiMg
*/

char Buffer[300], Buffer0[80], Buffer1[80];
const int maxNum = numeric_limits<int>::max();

struct Solution {

    unordered_map<string, vector<string>> replace;
    set<string> have1;
    string input;
    int answer2 = numeric_limits<int>::max();
    

    // 本题递归无解，运算量太大
    void calculate2 (const string& in, int step) { // 每次找到一个可替换的替换
        if(in.length() > input.length()) {
            return;
        }
        // cout << "input : " << in << endl;
        // cout << "step " << step << endl;
        if(in == input) {
            if(step < answer2) {
                answer2 = step;
            }
        }
        for(unordered_map<string, vector<string>>::iterator it = replace.begin(); it != replace.end(); it++) {
            string temp = it -> first; // 当前 key
            int len = temp.length();
            int pos = 0;
            int find = 0;
            while (find != -1 && pos < in.size()) {
                // cout << "key " << temp << endl;
                find = in.find(temp, pos);
                if(find != -1) {
                    for(int i = 0; i < it->second.size(); i++) {
                        string ne = in;
                        ne.replace(ne.begin() + find, ne.begin() + find + len, it->second[i]);
                        // cout << "ne " << ne << endl;
                        int next = step + 1;
                        calculate2(ne, next);
                    }
                    pos = find + len;
                }
            }
        }
        return;
    }

    void calculate1 (const string& input) { // 每次找到一个可替换的替换

        for(unordered_map<string, vector<string>>::iterator it = replace.begin(); it != replace.end(); it++) {
            string temp = it -> first; // 当前 key
            int len = temp.length();
            int pos = 0;
            int find = 0;
            while (find != -1) {
                find = input.find(temp, pos);
                if(find != -1) {
                    for(int i = 0; i < it->second.size(); i++) {
                        string ne = input;
                        ne.replace(ne.begin() + find, ne.begin() + find + len, it->second[i]);
                        // cout << "input " << input <<endl; 
                        // cout << "after " << ne << endl;
                        have1.insert(ne);
                    }
                    pos = find + len;
                }
            }
        }
    }

    void Solve() {
        while(true) {
            int num = scanf("%s => %s\n", Buffer0, Buffer1);
            if(num == 2) {
                replace[Buffer0].push_back(Buffer1);
            } else if(num == 1) {
                input = Buffer0;
            } else break;
        }

        int answer1;
        calculate1(input);
        answer1 = int(have1.size());
        printf("%d\n", answer1);

        for(int i = 0; i < replace["e"].size(); i++) {
            cout << replace["e"][i] << endl;
            calculate2(replace["e"][i], 1);
        }
        printf("%d\n", answer2);
    }
};

int main() {
    Solution().Solve();
    return 0;
}

// unordered_map<string, vector<string> > replace;
// set<string>