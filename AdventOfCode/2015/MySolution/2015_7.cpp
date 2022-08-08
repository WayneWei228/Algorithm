#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <cctype>
using namespace std;
char Buffer0[80], Buffer1[80], Buffer2[80];


/*                
123 -> x 
456 -> y
x AND y -> d
x OR y -> e
x LSHIFT 2 -> f
y RSHIFT 2 -> g
NOT x -> h
NOT y -> i

d: 72
e: 507
f: 492
g: 114
h: 65412
i: 65079
x: 123
y: 456
*/


struct Solution {
    vector<string> V;
    unordered_map<string, unsigned short> dic;

    void DefineType(const string& input) {
        int n;
        unsigned short num;
        if(sscanf(input.c_str(), "%d -> %s", &n, Buffer1) == 2) {
            dic[Buffer1] = n;
            return;
        }
        if(sscanf(input.c_str(), "%s AND %s -> %s", Buffer0, Buffer1, Buffer2) == 3) {
            // cout << "Buffer[0] " << Buffer0[0] << endl;
            if(dic.find(Buffer0) == dic.end() || dic.find(Buffer1) == dic.end()) return;
            unsigned short x = 0, y = 0;
            bool flag1 = false, flag2 = false;
            if(isdigit(Buffer0[0])) {
                x = (unsigned short)stoul(Buffer0, 0, 10);
                flag1 = true;
            }
            if(isdigit(Buffer1[0])) {
                y = (unsigned short)stoul(Buffer1, 0, 10);
                flag2 = true;
            }
            if(flag1 && flag2) {
                dic[Buffer2] = x & y;
                return;
            }

            if(flag1) {
                dic[Buffer2] = x & dic[Buffer1];
                return;
            }
            if(flag2) {
                dic[Buffer2] = dic[Buffer0] & y;
                return;
            }
            unsigned short temp = (dic[Buffer0] & dic[Buffer1]);
            dic[Buffer2] = temp;
            return;
        }
        if(sscanf(input.c_str(), "%s OR %s -> %s", Buffer0, Buffer1, Buffer2) == 3) {
            if(dic.find(Buffer0) == dic.end() || dic.find(Buffer1) == dic.end()) return;
            unsigned short x = 0, y = 0;
            bool flag1 = false, flag2 = false;
            if(isdigit(Buffer0[0])) {
                x = (unsigned short)stoul(Buffer0, 0, 10);
                flag1 = true;
            }
            if(isdigit(Buffer1[0])) {
                y = (unsigned short)stoul(Buffer1, 0, 10);
                flag2 = true;
            }
            // cout << "x " << x << " y " << y << endl;
            if(flag1 && flag2) {
                dic[Buffer2] = x | y;
                return;
            }
                // cout << "11111" << endl;

            if(flag1) {
                dic[Buffer2] = x | dic[Buffer1];
                return;
            }
                // cout << "222222" << endl;

            if(flag2) {
                dic[Buffer2] = dic[Buffer0] | y;
                return;
            }
            // cout << "left :" << dic[Buffer0] << " right :" << dic[Buffer1] << endl;

            unsigned short temp = (dic[Buffer0] | dic[Buffer1]);
            // cout << "temp " << temp << endl;

            dic[Buffer2] = temp;
            // cout << "dic[Buffer2] " << dic[Buffer2] << endl;

            return;
        }
        if(sscanf(input.c_str(), "%s LSHIFT %d -> %s", Buffer0, &n, Buffer1) == 3) {
            if(dic.find(Buffer0) == dic.end()) return;
            unsigned short temp = (unsigned short)(dic[Buffer0] << n);
            dic[Buffer1] = temp;
            return;
        }
        if(sscanf(input.c_str(), "%s RSHIFT %d -> %s", Buffer0, &n, Buffer1) == 3) {
            if(dic.find(Buffer0) == dic.end()) return;
            unsigned short temp = (unsigned short)(dic[Buffer0] >> n);
            dic[Buffer1] = temp;
            return;
        }
        if(sscanf(input.c_str(), "NOT %s -> %s", Buffer0, Buffer1) == 2) {
            if(dic.find(Buffer0) == dic.end()) return;
            unsigned short y = ~dic[Buffer0];
            dic[Buffer1] = y;
            return;
        }
    }



    void Solve() {
        while (true) {
            if(scanf("%[^\n]\n", Buffer0) < 1) break;
            DefineType(Buffer0);
        }
        for(unordered_map<string, unsigned short>::iterator it = dic.begin(); it != dic.end(); it++) {
            cout << it -> first << " " << it -> second << endl;
        }
        cout << endl;
    }
};


int main() {
    Solution().Solve();
    return 0;
}