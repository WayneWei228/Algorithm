/*
ID: waynewei
PROB: ride
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    freopen("ride.in", "r", stdin);
    freopen("ride.out", "w", stdout);
    string a, b;
    ll c = 1, d = 1;

    cin >> a >> b;
    for(string::iterator it = a.begin(); it != a.end(); it++) {
        c *= (int)*it - 64;
    }
    for(string::iterator it = b.begin(); it != b.end(); it++) {
        d *= (int)*it - 64;
    }
    c %= 47;
    d %= 47;
    if(c == d) {
        cout << "GO" << endl;
    } else
    {
        cout << "STAY" << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

/*
"""
LANG: PYTHON2
"""
def char_to_num(c):
    return ord(c) - ord('A') + 1

def line_to_code(s):
    nums = map(char_to_num, s) 
    code = reduce(lambda x,y: x*y, nums) % 47 
    return code

with open("ride.in", "r") as input_file:
    raw_lines = input_file.readlines()
lines = map(lambda s: s.strip(), raw_lines)
codes = map(line_to_code, lines)
should_go = codes[0] == codes[1]

with open("ride.out", "w") as output_file:
    if should_go: output_file.write("GO\n") 
    else: output_file.write("STAY\n")
*/